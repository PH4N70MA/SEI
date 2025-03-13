Laboratoarele în cardul obiectului SEI se vor executa pe placa de dezvoltare: STM NUCLEO L031K6 
Pentru utilizarea acestui template:
1. În Visual Studio Code se va crea un proiect nou
2. Bord: L031K6
3. Framework: STM32CUBE
   
![{E1323264-1BE1-4237-9B80-81410B8096B8}](https://github.com/user-attachments/assets/ac5bcc72-fd56-4fd7-9ff2-200179e6f66a)

5. După generarea proicetului pe calculator ne va muta în proiect
6. Apăsăm click dreapta pe denumirea proiectului și selectăm: _Reveal in File Explorer_ (sau combinașia Shift+Alt+R)
![{1210D7B9-FF55-4C11-B3BD-A1671D9AB435}](https://github.com/user-attachments/assets/9dcc5739-c793-4edb-90a7-26ba9406292f)
8. În directoria deschisă copiăm toate fișiere din template, în fereastra care va apărea se apasă: _Replace the file in the destination_
![{BA913E9B-B945-4A63-8D75-D515A2221F2A}](https://github.com/user-attachments/assets/d31e2085-2cb9-4e29-bfb0-52057ce373ba)
9. Pentru a verifica dacă totul a fost efectuat corect se va da buil. Bildul trebuie să se execute fără erori
10. Mapa src poate fi ștearsă din proiect
11. Acum se va deschide Cube_MX_File.ioc conform puntului 6(fișierul trebuie să se deschidă cu CubeMX)
12. Setăm microcontrolerul după necesitățile necesare, și generăm codul din nou
13. Proiectul este gata setat pentru lucru

La moment aceasta este procedura de creare a unui proiect STM pentru SEI
