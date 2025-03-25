#include "my_task.h"

SemaphoreHandle_t xButtonSemaphore;
QueueSetHandle_t xIncrement;

void freeRTOSInit(void)
{
    xTaskCreate(buttonLedTask, "Button Led", STACK_SIZE, NULL, PRIORITY, NULL);
    xTaskCreate(sincronizedTask, "N increment", STACK_SIZE, NULL, PRIORITY, NULL);
}

void buttonLedTaskSetup(void)
{
    if (xButtonSemaphore == NULL)
    {
        xButtonSemaphore = xSemaphoreCreateBinary();
        if (xButtonSemaphore != NULL)
        {
            // xSemaphoreGive(xButtonSemaphore);
        }
    }

    pinMode(ON_OFF_BUTTON, INPUT_PULLUP);
    pinMode(GREEN_LED, OUTPUT);
}

void buttonLedTask(void *pvParameters)
{
    uint8_t needInit = true;
    uint8_t ledState = LOW;
    TickType_t ledOnStateTime = 0;

    TickType_t relativeTime = 0;

    if (needInit)
    {
        buttonLedTaskSetup();
        needInit = false;
    }
	
	while (true)
	{
		if (!digitalRead(ON_OFF_BUTTON))
		{
			if (relativeTime < xTaskGetTickCount())
			{
                ledState = HIGH;
                xSemaphoreGive(xButtonSemaphore);
			}
		  relativeTime = xTaskGetTickCount() + pdMS_TO_TICKS(BUTTON_REFRESH_TIME);
		}

        if (ledState == HIGH)
        {
            ledState = LOW;
            digitalWrite(GREEN_LED, HIGH);
            ledOnStateTime = xTaskGetTickCount() + pdMS_TO_TICKS(GREEN_LED_ON_TIME);
        }

        if (ledOnStateTime < xTaskGetTickCount())
        {
            digitalWrite(GREEN_LED, LOW);
        }

		vTaskDelay(pdMS_TO_TICKS(FIRST_TASK_REC));
	}
}

void sincronizedTaskSetup(void)
{
    pinMode(BLUE_LED, OUTPUT);
    if (xIncrement == NULL)
    {
        xIncrement = xQueueCreate(1, sizeof(uint32_t));
    }
}

void sincronizedTask(void *pvParameters)
{
    uint32_t toggleCount = 0;
    uint8_t needInit = true;
    uint32_t N = 0;

    TickType_t ledStateTime = 0;

    if (needInit)
    {
        sincronizedTaskSetup();
        needInit = false;
    }

    while (true)
    {

        if (toggleCount && (ledStateTime < xTaskGetTickCount()))
        {
            if (toggleCount % 2)
            {
                digitalWrite(BLUE_LED, HIGH);
                ledStateTime = xTaskGetTickCount() + pdMS_TO_TICKS(BLUE_LED_ON_TIME);
            }
            else
            {
                digitalWrite(BLUE_LED, LOW);
                ledStateTime = xTaskGetTickCount() + pdMS_TO_TICKS(BLUE_LED_OFF_TIME);
            }
            toggleCount--;
        }

        
        if (xSemaphoreTake(xButtonSemaphore, pdMS_TO_TICKS(SECOND_TASK_REC)) == pdTRUE)
        {
            digitalWrite(BLUE_LED, !digitalRead(BLUE_LED));
            N++;
            toggleCount = N;
            xQueueSend(xIncrement, &N, 0);
        }

    }
}