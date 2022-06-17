//191307012 BERK AKIN
#include <locale>
#include <iostream>
using namespace std;
struct Stack
{
	int değer;
	Stack* sonraki;
};
struct stack
{
	Stack* Tos = NULL;
	int q = 0;
};
bool boşmu(stack* yığın)
{
	return (yığın->q == 5);
}
void Koy(stack* yığın, int a)
{
	Stack* geçici = new Stack();
	geçici->değer = a;
	if (boşmu(yığın))
	{
		cout << "Yığının İçi Boş,Eleman EKleniyor" << endl;
		yığın->Tos = geçici;
		yığın->Tos->sonraki = NULL;
		yığın->q++;
	}
	else
	{
		geçici->sonraki = yığın->Tos;
		yığın->Tos = geçici;
		yığın->q++;
	}
}
void Çek(stack* yığın)
{
	if (boşmu(yığın))
	{
		cout << "Yığın Boş" << endl;
	}
	else
	{
		Stack* geçici = yığın->Tos->sonraki;
		delete yığın->Tos;
		yığın->Tos = geçici;
		yığın->q--;
	}
}
void Yazdır(stack* yığın)
{
	if (boşmu(yığın))
	{
		cout << "Yığın Boş" << endl;
	}
	else
	{
		Stack* geçici = yığın->Tos;
		cout << "Yığın: ";
		while (geçici->sonraki != NULL)
		{
			cout << geçici->değer << " ";
			geçici = geçici->sonraki;
		}
		cout << geçici->değer << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	stack Yeni_Kuyruk;
	int işlem;
	int giriş;
	do
	{
		cout << "Yapılmak İstenen İşlemi Seçin\n(1)Ekleme\n(2)Silme\n(3)Yazdırma\n(4)Çıkış" << endl;
		cin >> işlem;
		if (işlem == 1)
		{
			cout << "Eklenecek Sayı:";
			cin >> giriş;
			Koy(&Yeni_Kuyruk, giriş);
		}
		else if (işlem == 2)
		{
			Çek(&Yeni_Kuyruk);
		}
		else if (işlem == 3)
		{
			Yazdır(&Yeni_Kuyruk);
		}
		else if (işlem == 4)
		{
			cout << "Çıkış Yapılıyor" << endl;
		}
		else
		{
			cout << "Yanlış İşlem Numarası Seçildi." << endl;
		}
	} while (işlem != 4);
	return 41;
}
