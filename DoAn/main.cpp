#include "game.h"
#include "consoleM.h"
#include "saveLoadGame.h"

void manhinhchinh();

void huongdan()
{
    system("cls");
    cout << "\n\tLuc dau khi vao game se xuat hien cac xe chay qua lai va mot ki tu \"Y\" dai dien cho nguoi qua duong, nguoi choi su dung cac phim 'W', 'A', 'S', 'D' de dieu chinh huong di chuyen cua nguoi qua duong va co gang tranh cac xe." << endl;
    cout << "\tKhi \"Y\" va cham cac xe thi chuong trinh thong bao yeu cau nguoi choi chon phim 'y' neu muon tiep tuc (chuong trinh reset tro choi lai nhu luc ban dau) hoac chon 'bat ki phim nao' neu muon thoat tro choi."<<endl;
    cout <<"\tKhi \"Y\" di qua duoc het cac xe thi thi toc do xe di chuyen nhanh hon, nghia la len 1 cap (Vi tri cua \"Y\" moi se xuat hien tro lai). Khi len cap 3 thi du lieu se reset lai nhu luc ban dau."<<endl;
    cout << "\tNhan phim bat ki de tro lai." << endl;
     system("pause");
    cout << endl;
    manhinhchinh();
}

void manhinhchinh()
{
    system("cls");
    cout << endl << endl;
    cout << "\tXin chao ban den voi tro choi cua chung toi" << endl;
    cout << "\tNhan phim bat ki de bat dau tro choi moi" << endl;
    cout << "\tNhan phim T de mo tro choi da luu" << endl;
    cout << "\tNhan phim H de xem huong dan" << endl;
    cout << "\tNhan phim ESC thoat tro choi" << endl;
    
    int temp;
    temp = toupper(_getch());
    switch (temp) {
    case 'T':
        loadFile();
        break;
    case 'H':
        huongdan();
        break;
    case 27: 
        exit(0);
        break;
    default:
        StartGame();
    }
}

int main()
{
    int temp;
    system("color 09");
    FixConsoleWindow();
    ShowConsoleCursor(false);
    srand(time(NULL));
    manhinhchinh();
    thread t1(SubThread);
    while (1)
    {
        temp = toupper(_getch());
        if (STATE == 1)
        {
            if (temp == 27)
            {
                ExitGame((HANDLE)t1.native_handle());
                return 0;
            }
            else if (temp == 'P')
            {
                PauseGame((HANDLE)t1.native_handle());
            }
            else if (temp == 'T')
            {
                loadFile();
            }
            else if (temp == 'L')
            {
                PauseGame((HANDLE)t1.native_handle());
                saveFile();
            }
            else if (flag)
            {
                ResumeThread((HANDLE)t1.native_handle());
                if (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S')
                {
                    MOVING = temp;
                }
            }
        }
        else
        {
            if (temp == 'Y')
                StartGame();
            else
            {
                ExitGame((HANDLE)t1.native_handle());
                return 0;
            }
        }
    }
    return 0;
}