/****************************************************************************
**						SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**					BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**					  PROGRAMLAMAYA GİRİŞİ DERSİ
**
**                   ÖDEV NUMARASI.......: PROJE-1
**                   ÖĞRENCİ ADI........ : FUAD GARIBLI
**                   ÖĞRENCİ NUMARASI... : G20120558
**                   DERS GRUBU......... : 2.ÖĞRETİM "A" GRUBU
****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <locale.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;
//---------------------MENU-----------------------
void menu()//MENÜ 2 kez kullandığım için fonksiyon olarak yazmak daha kullanışlı oldu
{ 
	cout << endl<<endl;
	cout << "       ***** ISLEMLER MENUSU *****       " << endl;
	cout << "____________________________________________" << endl;
	cout << "|Çikis.....................................0|" << endl;
	cout << "____________________________________________" << endl;
	cout << "|Okuyucu Kaydi.............................1|" << endl;
	cout << "____________________________________________" << endl;
	cout << "|Okuyucu Kaydi Guncelleme..................2|" << endl;
	cout << "____________________________________________" << endl;
	cout << "|Okuyucu Silme.............................3|" << endl;
	cout << "____________________________________________" << endl;
	cout << "|Okuyucu Uzerindeki Kitaplarin Listesi.....4|" << endl;
	cout << "____________________________________________" << endl;
	cout << "|Okuyucu Kitap Odunc Alma..................5|" << endl;
	cout << "____________________________________________" << endl;
	cout << "|Okuyucu Kitap Geri Döndündürme............6|" << endl;
	cout << "____________________________________________" << endl;
	cout << "|Kitap Ekleme..............................7|" << endl;
	cout << "____________________________________________" << endl;
	cout << "|Kitap Silme...............................8|" << endl;
	cout << "____________________________________________" << endl;
	cout << "|Kitap Duzeltme............................9|" << endl;
	cout << "____________________________________________" << endl;

}
int main()
{
	setlocale(LC_ALL, "turkish");
	int secim, tekrar = 4, islem = 0, islem_1 = 0, kosul, eski_kitap_alinabil;
	string degisecek;//odunc alma işlemi ve geri döndürme işleminden sonra okuyucunun kitap alma limitinin yani kitap_alınabilir değişkenin yeniden değer atama yapılmasında kullanılacak değişken
	char cevap;
	//-------kullanıcı bilgileri-----
	string ad, sifre, giris, cikis;
	//-------okuyucu bilgi----------
	string okuyucu_TC, okuyucu_adi, okuyucu_soyadi, dogum_tarihi, tel, uye_numarasi, gorev;
	int kitap_alınabilir;
	//--------kitap bilgileri------
	string ISBN_kitap, kitap_isim, yazar_adi, yazar_soyadi, konu, tur, sayfa_sayi;
	//------Odunç verilenler--------
	string ISBN_odunc, odunc_tarihi, donus_tarihi;
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	cout << "Giris icin lutfen kullanici bilgilerini giriniz:" << endl;
	cout << endl;
	cout << "=============================================" << endl;
	cout << "||KULLANICI AD...............:"; cin >> ad;
	cout << "=============================================" << endl;
	cout << "||KULLANICI SIFRE............:"; cin >> sifre; 
	cout << "=============================================" << endl;
	int kosul_01 = 0;//kayıtlı olup olmadığını denetlemek için kullanılacak kosul değişkeni
	string k_ad, k_sifre;
	ifstream DosyaOku("kullanicilar.txt");
	while (kosul_01 == 0 && !(DosyaOku.eof()))//dosyanın sonuna kadar değerleri tek tek alan while döngüsü
	{

		DosyaOku >> k_ad >> k_sifre >> giris >> cikis;//her seferinde değerler yeniden alınır
		if (ad == k_ad && sifre == k_sifre)
		{

			kosul_01++;//kosul değişkeni 1 arttırılır
		}
	}
	cout << endl;
	DosyaOku.close();

	if (kosul_01 != 0)
	{
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, sizeof(buffer), "%d-%m-%Y|%H:%M:%S", timeinfo);
		string str(buffer);
		cout << "KULLANICI GIRIS SAATI...............:" << str << endl;
		giris = str;
		menu();
		for (tekrar; tekrar > 0; tekrar--)//kullanıcı yanlış secim yaptığında 3 kez tekrar secim yaptıran for döngüsü
		{
			cout << "\nislem secin....:";
			cin >> secim;
			cout << endl;
			//-----------OKUYUCU KAYDI----------**
			if (secim == 1)
			{
				int kosul_1 = 0;//TC numarasının kayıtlı olup olmadığını denetlemek için kullanılacak kosul değişkeni
				string TC;
				islem_1 = 0;
				ofstream DosyaYaz;
				DosyaYaz.open("okuyucu.txt", ios::app);
				ifstream DosyaOku("okuyucu.txt");
				system("cls");
				cout << "//OKUYUCU KAYIT" << endl << "* * * TURKCE KARAKTER KULLANMAYINIZ * * *" << endl;
				cout << "OKUYUCU TC............................:"; cin >> TC;
				kosul_1 = 0;
				while (kosul_1 == 0 && !(DosyaOku.eof()))//dosyanın sonuna kadar değerleri tek tek alan while döngüsü
				{
					DosyaOku >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_alınabilir;//her seferinde değerler yeniden alınır
					if (TC == okuyucu_TC)//eger kayıdı yapılmak istenen okuyucunun TC numarası var ise
					{
						cout << "GIRDIGINIZ TC KIMLIK NUMARASI KAYITLIDIR. ISLEM YAPILAMAZ!" << endl;
						kosul_1++;//kosul değişkeni 1 arttırılır
					}
				}
				if (kosul_1 == 0)//kosul değişkeni "0"a eşitse kimik numarası kayıt edile bilir demektir
				{
					cout << "OKUYUCU ADI...........................:"; cin >> okuyucu_adi;
					cout << "OKUYUCU SOYADI........................:"; cin >> okuyucu_soyadi;
					cout << "DOGUM TARIHI(gg/aa/yy)................:"; cin >> dogum_tarihi;
					cout << "TELEFON...............................:"; cin >> tel;
					cout << "UYE NUMARASI..........................:"; cin >> uye_numarasi;
					cout << "GOREVI................................:"; cin >> gorev;
					cout << "ALINA BILIR KITAP SAYI................:"; cin >> kitap_alınabilir;
					okuyucu_TC = TC;
					//gerekli bilgiler tek tek kullanıcı tarafından girilir
					DosyaYaz << "\n" << okuyucu_TC << " " << okuyucu_adi << ' ' << okuyucu_soyadi << ' '
						<< dogum_tarihi << ' ' << tel << ' ' << uye_numarasi << ' ' << gorev << ' ' << kitap_alınabilir;//ve dosyaya yazdırılır
				}
				DosyaOku.close();
				if (kosul_1 == 0)
				{
					cout << "OKUCU KAYIT ISLEMI BASARILI" << endl;//uygun mesaj ekrana yazdırılır
				}
				islem = 1;
				tekrar = -1;
			}
			//-------------CIKIS----------------
			else if (secim == 0)
			{
				time(&rawtime);
				timeinfo = localtime(&rawtime);
				strftime(buffer, sizeof(buffer), "%d-%m-%Y|%H:%M:%S", timeinfo);
				string str(buffer);
				cout << "KULLANICI CIKIS SAATI................:" << str << endl;
				cikis = str;
				ofstream DosyaYaz;
				DosyaYaz.open("kullanıcılar.txt", ios::app);
				DosyaYaz << '\n' << ad << ' ' << sifre << ' ' << giris << ' ' << cikis;

				tekrar = -1;
			}
			//------------KAYIT GÜNCELLEME--------***
			else if (secim == 2)
			{
				kosul = 0;
				system("cls");
				string gecici = "*";//aynı verinin tekrar kaydını önlemek için kullndığım değişken
				string deneme_tc, okuyucu_TCodunc;//okuyucu.txt dosyasındaki verilerle kullanıcın girdiği ISBN numarasını karşılaştırmada kullandığım değişken
				int odunc_kosul = 0, dongu_onle = 0;//kayıt tekrarı olmasına karşın döngüyü sonlandıramak için kullanılan değişken
				cout << "//KAYIT GUNCELLEME" << endl;
				cout << "TURKCE KARAKTER KULLANMAYINIZ" << endl;
				cout << "OKUYUCU TC............................:"; cin >> deneme_tc;
				ifstream DosyaOku_1("odunc.txt");
				while (DosyaOku_1.eof() == 0)
				{
					DosyaOku_1 >> okuyucu_TCodunc >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
						>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//okuyucunun üzerinde kitap olup olmadığını denetlemek için odunc dosyasındaki verileri alıyoruz
					cout << sayfa_sayi << endl;
					if (deneme_tc == okuyucu_TCodunc)
					{
						odunc_kosul = 1;
					}
				}
				kosul = 0;
				DosyaOku_1.close();
				if (odunc_kosul == 0)
				{
					ifstream DosyaOku("okuyucu.txt");
					ofstream DosyaYaz("kopyala.tmp");// .tmp geçici bir dosya türüdür
					while (!(DosyaOku.eof()))//dosya sonuna kadar okunur
					{
						DosyaOku >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_alınabilir;//her seferinde dosyadaki veriler değişkenlere atanır

						if (deneme_tc == okuyucu_TC && dongu_onle == 0)//kullanıcının değiştirmek istediği kayıt bulunur ve olası kayıt tekrarını önlemek için koşula i==0 ilavesini yaptım
						{
							cout << "OKUYUCU BILGIERI" << endl;
							cout << "OKUCU TC..............................:" << okuyucu_TC << endl;
							cout << "OKUYUCU ADI...........................:" << okuyucu_adi << endl;
							cout << "OKUCU SOYADI..........................:" << okuyucu_soyadi << endl;
							cout << "DOGUM TARIHI(gg/aa/yy)................:" << dogum_tarihi << endl;
							cout << "TELEFON...............................:" << tel << endl;
							cout << "UYE NUMARASI..........................:" << uye_numarasi << endl;
							cout << "GOREVI............................:...." << gorev << endl;
							cout << "ALINA BILIR KITAP SAYI................:" << kitap_alınabilir << endl;
							kosul++;//kosul değerinin 1 arttırılması kullanıcının girdiği TC kimlik numarasına uygun kaydın bulunduğu anlamına gelir
							cout << "OKUYUCU BILGIERINI DEGISTIRMEK ICIN DEVAM EDIN" << endl;
							cout << "OKUYUCU TC............................:"; cin >> okuyucu_TC;
							cout << "OKUYUCU ADI...........................:"; cin >> okuyucu_adi;
							cout << "OKUYUCU SOYADI........................:"; cin >> okuyucu_soyadi;
							cout << "DOGUM TARIHI(gg/aa/yy)................:"; cin >> dogum_tarihi;
							cout << "TELEFON...............................:"; cin >> tel;
							cout << "UYE NUMARASI..........................:"; cin >> uye_numarasi;
							cout << "GOREVI................................:"; cin >> gorev;
							cout << "ALINA BILIR KITAP SAYI................:"; cin >> kitap_alınabilir;
							dongu_onle++;//döngü bitene kadar bu if koşuluna maksimum 1 kez girilmesini sağlamak amacıyla i değeri 1 arttırılır 
							DosyaYaz << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " " << tel << " " << uye_numarasi << " " << gorev << " " << kitap_alınabilir << "\n";//kullanıcının girdiği güncel değerler kayd edilir
							gecici = okuyucu_TC;//bir sonraki döngüde ve alttaki if döngüsünde TC numaraları aynı olan okuyucuların kaydını önlemek için okuyucu_TC değişkenin değeri gecici değişkeninde tutulur
						}
						if (okuyucu_TC != gecici)//her 2 okuyucunun TC numarası farklıysa koşulun içine girer
						{
							DosyaYaz << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " " << tel << " " << uye_numarasi << " " << gorev << " " << kitap_alınabilir << "\n";//verileri kayd eder
							gecici = okuyucu_TC; //bir sonraki döngüde TC numaraları aynı olan okuyucuların kaydını önlemek için okuyucu_TC değişkenin değiri gecici değişkeninde tutulur
						}
					}
					if (kosul == 0)
					{
						cout << "BU TC NUMARASI KAYITLI DEGIL, YENIDEN DENEYIN" << endl;
					}
					else
					{
						cout << "KAYIT GUNCELLEME BASARILI" << endl;
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove("okuyucu.txt");
					rename("kopyala.tmp", "okuyucu.txt");
				}
				if (odunc_kosul == 1)
				{
					cout << "OKUYUCU KITAPLARI DONDURMEDIGI SURECE GUNCELLENEMEZ" << endl;
				}
				islem = 1;
				tekrar = -1;
			}
			//--------------KAYIT SİLME-------------**
			else if (secim == 3)
			{
				int odunc_kosul = 0;
				kosul = 0;//uygun mesajları ekrana çıkarmaya yardım eden değişken
				string deneme_TC;//.txt dosyasındaki verilerle kullanıcının girdiği verileri karşılaştırmaya yardım eden değişken
				system("cls");
				cout << "//OKUYUCU KAYIT SILME" << endl;
				cout << "SILMEK ISTEDIGINIZ OKUYUCUNUN TC NUMARASINI GIRIN...............:"; cin >> deneme_TC;//kullanıcı deneme_TC değişkenine değer atar
				ifstream DosyaOku_1("odunc.txt");
				string  okuyucu_TCodunc;
				while (!(DosyaOku_1.eof()))
				{
					DosyaOku_1 >> okuyucu_TCodunc >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
						>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//okuyucunun üzerinde kitap olup olmadığını denetlemek için odunc dosyasındaki verileri alıyoruz
					if (deneme_TC == okuyucu_TCodunc)
					{
						odunc_kosul = 1;
					}
				}
				DosyaOku_1.close();
				if (odunc_kosul == 0)
				{
					ifstream DosyaOku("okuyucu.txt");
					ofstream DosyaYaz("kopya.tmp");
					string gecici = "*";//dosyaya veri aktarılırken TC numarası aynı olan kayıtların önlenmesine yardım eder
					while (DosyaOku.eof() == 0)
					{
						DosyaOku >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_alınabilir;//dosyadaki veriler uygun değişkenlere atanır
						if (deneme_TC == okuyucu_TC)
						{
							kosul++;//her hangi 2 TC numarası bir birine eşitse kosul 1 arttırılır
						}
						if (okuyucu_TC != gecici)//dosyanın sonunda aynı TC numarılı kayıdın 2 kez yazılmasını önler
						{
							if (deneme_TC != okuyucu_TC)
							{
								DosyaYaz << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " "
									<< tel << " " << uye_numarasi << " " << gorev << " " << kitap_alınabilir << "\n";//veriler dosyaya kayd edilir
							}
							gecici = okuyucu_TC;
						}
					}

					if (kosul == 0)//TC numarası kayıtlı olmadığı durumda uygun mesaj gösterilir
					{
						cout << endl << "BU TC NUMARASI KAYITLI DEGIL, YENIDEN DENEYIN" << endl;
					}
					else
					{
						cout << endl << "KAYIT SILME ISLEMI BASARILI" << endl;
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove("okuyucu.txt");//eski dosya silinir
					rename("kopya.tmp", "okuyucu.txt");//kopya.tmp okuyucu.txt olarak yeniden adlandırılır
				}
				else
				{
					cout << endl << "OKUYUCU UZERINDEKI KITAPLAR TESLIM EDILMEDI. SIMDI SILINEMEZ" << endl;
				}
				islem = 1;
				tekrar = -1;
			}
			//----OKUYUCU UZERİNDEKİ KİTAPLAR LİSTESİ-----*********
			else if (secim == 4)
			{
				system("cls");
				kosul = 0;//TC numarasıyla ilgili kayıt olmaması durumunda uygun mesajların göstermede kullanılacak değişken
				string ISBN_kontrol = "*";// olası yazdırma tekrarını önlemek için kullanılan deneme_ISBN değişkeni
				string deneme_TC; // hangi kullanıcının kaydının gösterileceğini tutan deneme_TC değişkeni
				ifstream DosyaOku("odunc.txt");
				cout << "//OKUYUCU UZERINDEKI KITAP LISTESI" << endl
					<< "KITAPLARI LISTELENECEK OKUYUCUNUN TC NUMARASINI GIRIN.............:"; cin >> deneme_TC;//kullanıcı tarafından klavyeden değer girilir
				while (DosyaOku.eof() == 0)//dosya sonuna kadar okunur
				{
					okuyucu_TC = "0=-=0";
					DosyaOku >> okuyucu_TC >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;
					if (kosul == 0 && deneme_TC == okuyucu_TC)//listeleme başında bir kezekranda gösterilecek okuyucu bilgileri
					{
						cout << "OKUYUCU ADI................:" << okuyucu_adi << endl;
						cout << "OKUYUCU SOYADI.............:" << okuyucu_soyadi << endl;
						kosul = 1;//bu işlemin tekrarını önlemek için değişken 1 arttırılır
					}
					if (deneme_TC == okuyucu_TC && ISBN_kontrol != ISBN_kitap)//kullanıcının girdiği veriye eşit olan kayıt bulunduktan sonra uygun mesajlar ekrana yazdırılır
					{
						cout << "KITAP ISBN.............:" << ISBN_kitap << endl
							<< "KITAP ISMI.............:" << kitap_isim << endl
							<< "ALINMA TARIHI..........:" << odunc_tarihi << endl
							<< "DONUŞ TARIHI...........:" << donus_tarihi << endl;
						ISBN_kontrol = ISBN_kitap;
					}
				}
				if (kosul == 0)//eğer ki hiç bir işlem yapılmazsa kullanıcının girdiği veriye uygun kayıt yoktur demektir
				{
					cout << "BU OKUYUCUYA DAIR KITAP KAYDI BULUNMAMAKTADIR" << endl;//uygun mesaj ekrana yazdırılır
				}
				DosyaOku.close();
				islem = 1;
				tekrar = -1;
			}
			//--------OKUYUCU KİTAP ÖDÜNÇ ALMA-------------********
			else if (secim == 5)
			{
				system("cls");//ekran temizlenir
				kosul = 0;
				string deneme_TC, deneme_ISBN;//kullanıcının girdiği bilgilerin kayıtlı olup olmadığını denetlemede kullanılan değişkenler
				ifstream DosyaOku("okuyucu.txt");
				cout << "//KITAP ODUNC ALMA" << endl;
				cout << "ODUNC ALAN OKUYUCUNUN TC NUMARASINI GIRIN................:"; cin >> deneme_TC;//ilk olarak ödünç alan okuyucunun TC numarası kullanıcıdan alınır
				while (!(DosyaOku.eof()) && kosul == 0)
				{
					DosyaOku >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_alınabilir;//dosyadaki veriler değişkenlere atanır
					if (deneme_TC == okuyucu_TC)
					{
						kosul++;//dışarıdan girilen değerin kayıtlı olup olmamasını anlamamız için kosul değişkeni 1 arttırılır 
					}
				}
				if (kosul == 0)//eğer değişken arttırılmamışsa girilen TC numarsına uygun kayıt dosyada yoktur
				{
					cout << endl << "BU TC NUMARASI KAYITLI DEGIL, YENIDEN DENEYIN" << endl;
				}
				else
				{
					cout << "OKUYUCU ADI..................:" << okuyucu_adi << endl;
					cout << "OKUCU SOYADI.................:" << okuyucu_soyadi << endl;
					cout << "UYE NUMARASI.................:" << uye_numarasi << endl;
					cout << "ALINA BILIR KITAP SAYI.......:" << kitap_alınabilir << endl;//aksi durumda okuyucu bilgilerinin bir kısmı ekrana yazılır
					if (kitap_alınabilir > 0)//kullanıcının kitap alma limiti dolmamışsa ödünç kitap ala bilir
					{
						kosul = 0;//kosul değişkeni yeniden kullanılmak için sıfırlanır
						ifstream DosyaOku("kitap.txt");//kitap bilgileri bulanan kitap.txt dosyası açılır
						cout << "ALMAK ISTENEN KITABIN ISBN NUMARASI.........:"; cin >> deneme_ISBN; //denetlenecek ISBN değeri kullanıcı tarafından girilir
						while (!(DosyaOku.eof()) && kosul == 0)
						{
							DosyaOku >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//kitap.txt dosyasındaki veriler uygun değişkenlere atanır
							if (deneme_ISBN == ISBN_kitap)//burada da ISBN numarasının dosyada kayıtlı olup olmadığı denetlenir
							{
								kosul++;//değere eşit kayıt bulunduğunda kosş 1 artıırılır
							}
						}
						if (kosul == 0)//kosul hala ilk değerine eşitse girilen ISBN numarasına uygun kayıt mevcut değil demektir
						{
							cout << "BU ISBN NUMARASI KAYITLI DEGIL, YENIDEN DENEYIN" << endl;//uygun mesaj ekrana yazılır
						}
						else
						{
							cout << "KITAP ISMI...............:" << kitap_isim << endl;
							cout << "YAZAR ADI................:" << yazar_adi << endl;
							cout << "YAZAR SOYADI.............:" << yazar_soyadi << endl;
							cout << "KITAP KONUSU.............:" << konu << endl;
							cout << "KITAP TURU...............:" << tur << endl;
							cout << "SAYFA SAYI...............:" << sayfa_sayi << endl;
							time(&rawtime);
							timeinfo = localtime(&rawtime);
							strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
							string str(buffer);
							cout << "ODUNC VERILME TARIHI(gg/aa/yyyy)......:" << setw(32) << " " << str << endl; odunc_tarihi = str;
							time(&rawtime);
							timeinfo = localtime(&rawtime);
							if (timeinfo->tm_mon == 11)
							{
								timeinfo->tm_mon = 0;
								timeinfo->tm_year = 1 + timeinfo->tm_year;
							}
							else
							{
								timeinfo->tm_mon = timeinfo->tm_mon + 1;
							}
							strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
							string str1(buffer);
							cout << "GERI DONUS TARIHI(gg/aa/yyyy).........:" << setw(32) << " " << str1 << endl; donus_tarihi = str1;

							//kullanıcı tarafından ödünç alınma ve geri verilme tarihi girilir
							cout << "ODUNC ALMA ISLEMI BASARILI" << endl;
							string silinecek;//ödünç alınacak kitabı kitap.txt dosyasından silmemiz için kullanılıcak değişken
							ofstream DosyaYaz;
							DosyaYaz.open("odunc.txt", ios::app);//bilgilerin yazılıcağı odunc.txt dosyası açılır
							DosyaYaz << okuyucu_TC << " " << ISBN_kitap << " " << odunc_tarihi << " " << donus_tarihi << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << kitap_isim << " "
								<< yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//dosyaya veriler yazılır
							silinecek = ISBN_kitap;//odunc.txt dosyasına kayd edilen kitabın ISBN numarasını silinecek değişkeninde tutulur
							degisecek = okuyucu_TC;//kayd edilen okuyucunun kitap alma limitini 1 azaltmak için okuyucunun TC numarasını degisecek adlı değişkende tutulur
							DosyaOku.close();
							DosyaYaz.close();
							kosul = 0;
							ifstream DosyaOku_1("kitap.txt");//kitap.txt dosyasını odunc alınan kitabı silmek için tekrar açılır
							ofstream DosyaYaz_1("kopya.tmp");
							string gecici = "*";
							while (DosyaOku_1.eof() == 0)
							{
								DosyaOku_1 >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;
								if (silinecek == ISBN_kitap)//silinecek kitabı bulunur
								{
									kosul++;//bu kitabı kaydetmeden devam eder
								}
								if (ISBN_kitap != gecici)
								{
									if (silinecek != ISBN_kitap)
									{
										DosyaYaz_1 << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//geri kalan kitaplar kopyala.tmp dosyasına kayd edilir
									}
									gecici = ISBN_kitap;
								}
							}
							DosyaYaz_1.close();
							DosyaOku_1.close();
							remove("kitap.txt");
							rename("kopya.tmp", "kitap.txt");
							//------------iç içe çok fazla koşul ve döngü olduğu için okuyucunun kitap alma limitini dışarda değiştiriyorum. en dıştaki for döngüsünü sonlarında-------------------
							islem_1 = 1;//Bu değer programa ödünç alındığını bildirir. Okuyucunun kitap_alınabilir değişkeninin değerini 1 azaltan koşula girilmesini sağlayan değişkene değer atarım.
						}
					}
					else
					{
						cout << "UZGUNUZ SU ANDA KITAP ODUNC ALAMA LIMITINIZ DOLU" << endl;
					}
				}
				DosyaOku.close();
				islem = 1;
				tekrar = -1;
			}
			//--------KİTAP GERİ DÖNDÜRME-------
			else if (secim == 6)
			{
				string ISBN, gecici = "*", eklenecek;
				ifstream DosyaOku("odunc.txt");
				ofstream DosyaYaz;
				DosyaYaz.open("kopya.tmp");
				system("cls");
				int odunc_kosul = 0;
				cout << "//KITAP DONDURME" << endl
					<< "DONDURULEN KITABIN ISBN'SI........................:"; cin >> ISBN;
				ifstream DosyaOku_1("odunc.txt");
				while (!(DosyaOku_1.eof()))
				{
					DosyaOku_1 >> okuyucu_TC >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
						>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//kitabın ödünç alınıp alınmadığını denetliyor
					if (ISBN == ISBN_kitap)
					{
						odunc_kosul = 1;
					}
				}
				kosul = 0;
				DosyaOku_1.close();
				if (odunc_kosul == 1)
				{
					while (DosyaOku.eof() == 0)
					{
						DosyaOku >> okuyucu_TC >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;
						if (kosul == 0 && ISBN == ISBN_kitap)
						{
							degisecek = okuyucu_TC;
							cout << "KITABI ALAN OKUYUCUN ADI..........................:" << okuyucu_adi << endl;
							cout << "KITABI ALAN OKUYUCUN SOYADI........................:" << okuyucu_soyadi << endl;
							cout << "KITAP ISMI..........................:" << kitap_isim << endl;
							cout << "ALINMA TARIHI.......................:" << odunc_tarihi << endl;
							cout << "DONUS TARIHI........................:" << donus_tarihi << endl;
							kosul++;
							islem_1 = 2;
							eklenecek = ISBN_kitap;
							gecici = ISBN_kitap;
							ofstream DosyaYaz_1;
							DosyaYaz_1.open("kitap.txt", ios::app);
							DosyaYaz_1 << eklenecek << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//kitap yeniden kitap.txt dosyasına kayd edilir
							DosyaYaz_1.close();
						}
						if (ISBN != ISBN_kitap && gecici != ISBN_kitap)
						{
							DosyaYaz << okuyucu_TC << " " << ISBN_kitap << " " << odunc_tarihi << " " << donus_tarihi << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << kitap_isim << " "
								<< yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";
							gecici = ISBN_kitap;
						}
					}
					DosyaOku.close();
					DosyaYaz.close();
					remove("odunc.txt");
					rename("kopya.tmp", "odunc.txt");
				}
				if (odunc_kosul == 0)
				{
					cout << "BU ISBN NUMARASI ILE ILGILI KAYIT MEVCUT DEGIL" << endl;
				}
				islem = 1;
				tekrar = -1;
			}
			//-----------KİTAP EKLEME-----------******
			else if (secim == 7)
			{
				int kosul_1 = 0;//kayıtlı ISBN numarasının yeniden kayd edilmesini önlemede kullanılan kosul_1 değişkeni
				string ISBN;//kitap.txt dosyasındaki verilerle karşılaştırılacak değişken
				ofstream DosyaYaz;
				DosyaYaz.open("kitap.txt", ios::app);
				kosul_1 = 0;//değişken döngü her tekrar ettiğinde sıfırlanmasını sağlar
				ifstream DosyaOku("kitap.txt");
				system("cls");
				cout << "//KITAP EKLEME" << endl
					<< "* * * TURKCE KARAKTER KULLANMAYINIZ * * *" << endl
					<< "!!!BOSLUK YERINE \"_\" KARAKTERINI KULLANIN!!!" << endl;
				cout << "KITAP ISBN............................:"; cin >> ISBN;//kullanıcı değer girer
				while (kosul_1 == 0 && !(DosyaOku.eof()))//dosyası sonuna kadar okur eğer ISBN numarası kayıtlı ise durur
				{
					DosyaOku >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//değerler dosyadan alınır
					if (ISBN == ISBN_kitap)//kayıt edilmek istenen ISBN numarası denetlenir, eğer kayıtlı ise kosul_1 değişkenini 1 arttırır
					{
						cout << "GIRDIGINIZ ISBN NUMARASI KAYITLIDIR. ISLEM YAPILAMAZ!" << endl;
						kosul_1++;
					}
				}
				if (kosul_1 == 0)//ISBN kayıtlı değilse kullanıcı kayıt ede bilir
				{
					cout << "KITAP ISMI............................:"; cin >> kitap_isim;
					cout << "YAZAR ADI.............................:"; cin >> yazar_adi;
					cout << "YAZAR SOYADI..........................:"; cin >> yazar_soyadi;
					cout << "KITAP KONUSU..........................:"; cin >> konu;
					cout << "KITAP TURU............................:"; cin >> tur;
					cout << "SAYFA SAYI............................:"; cin >> sayfa_sayi;
					//kullanıcıdan değerler alınır
					ISBN_kitap = ISBN;
					DosyaYaz << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//kayıt yapılır
				}
				DosyaYaz.close();
				DosyaOku.close();
				cout << "* * * * * * KITAP EKLEME ISLEMI BASARILI * * * * * *" << endl;
				islem = 1;
				tekrar = -1;
			}
			//---------KİTAP SİLME-------------*************
			else if (secim == 8)
			{
				int odunc_kosul = 0;
				string okuyucu_TCodunc, deneme_ISBN;//kitap.txt ve odunc.txt dosyasındaki isbn numaraları ile karşılaştırılacak değişkenler tanımlanır
				system("cls");
				cout << "//KITAP SILME" << endl
					<< "SILMEK ISTEDIGINIZ KITABIN ISBN NUMARSINI GIRIN........:"; cin >> deneme_ISBN;//ISBN değeri kullanıcı tarafından girilir
				ifstream DosyaOku_1("odunc.txt");
				while (!(DosyaOku_1.eof()))
				{
					DosyaOku_1 >> okuyucu_TCodunc >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
						>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//okuyucunun üzerinde kitap olup olmadığını denetlemek için odunc dosyasındaki verileri alıyoruz
					if (deneme_ISBN == ISBN_kitap)
					{
						odunc_kosul = 1;
					}
				}
				kosul = 0;//ISBN numarasının kayıtlı olmaması durumunda ekrana mesaj çıkarmada kullanacağımız değişken
				DosyaOku_1.close();
				if (odunc_kosul == 0)
				{
					ifstream DosyaOku("kitap.txt");
					ofstream DosyaYaz("kopya.tmp");
					string gecici = "*";//ISBN numaralarının aynı olması durumunda kayıt edilmememsini sağlayan değişken
					while (DosyaOku.eof() == 0)//dosya sona kadar okunur
					{
						DosyaOku >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;
						if (deneme_ISBN == ISBN_kitap)
						{
							kosul++;//kullanıcının girdiği ISBN numarası .txt dosyasında mevcutsa kosul 1 arttırılır
						}
						int i = 0;
						if (ISBN_kitap != gecici)//Kayıt tekrarını önlemek için iç içe 2 kez denetleme yaptım
						{
							if (deneme_ISBN != ISBN_kitap)
							{
								DosyaYaz << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//dosyaya yazdırılır
							}
							gecici = ISBN_kitap;//bir sonraki döngüde kullanılmak üzere ISBN_kitap değişkenin değeri gecici değişkeninde tutlur
						}
					}
					if (kosul == 0)//eğer kosul 1 arttırılmadıysa ISBN numarası kayıtlı değil demektir
					{
						cout << "BU ISBN NUMARASI KAYITLI DEGIL, YENIDEN DENEYIN" << endl;

					}
					else
					{
						cout << "* * * * * * KAYIT SILME ISLEMI BASARILI * * * * * *" << endl;
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove("kitap.txt");//eski kitap.txt dosyası silinir
					rename("kopya.tmp", "kitap.txt");//kopya.tmp dosyası kitap.txt olarak kayıt edilir
				}
				else
				{
					cout << "KITAP DAHA IADE EDILMEDI SILINEMEZ" << endl;
				}
				islem = 1;
				tekrar = -1;
			}
			//KİTAP DÜZELTME*****
			else if (secim == 9)
			{
				system("cls");
				int odunc_kosul = 0;
				string gecici = "*";//aynı verinin tekrar kaydını önlemek için kullndığım değişken
				string deneme_ISBN;//kitap.txt dosyasındaki verilerle kullanıcın girdiği ISBN numarasını karşılaştırmada kullandığım değişken
				ifstream DosyaOku("kitap.txt");
				cout << "//KITAP DUZELTME         * * * TURKCE KARAKTER KULLANMAYINIZ * * *" << endl;
				cout << "KITAP ISBN...........................:"; cin >> deneme_ISBN;//kullanıcıdan değiştirilecek kitabın ISBN numarası girilir
				ifstream DosyaOku_1("odunc.txt");
				while (!(DosyaOku_1.eof()))
				{
					ISBN_kitap = "0=-=0";
					DosyaOku_1 >> okuyucu_TC >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
						>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//okuyucunun üzerinde kitap olup olmadığını denetlemek için odunc dosyasındaki verileri alıyoruz
					if (deneme_ISBN == ISBN_kitap)
					{
						odunc_kosul = 1;
					}
				}
				kosul = 0;//ISBN numarasının kayıtlı olmaması durumunda ekrana mesaj çıkarmada kullanacağımız değişken
				DosyaOku_1.close();
				if (odunc_kosul == 0)
				{
					ofstream DosyaYaz("kopyala.tmp");// .tmp geçici bir dosya türüdür
					kosul = 0;
					int dongu_onle = 0;//kayıt tekrarı olmasına karşın döngüyü sonlandıramak için kullanılan değişken
					while (!(DosyaOku.eof()))//dosya sonuna kadar okunur
					{
						DosyaOku >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//her seferinde dosyadaki veriler değişkenlere atanır
						if (deneme_ISBN == ISBN_kitap && dongu_onle == 0)//kullanıcının değiştirmek istediği kayıt bulunur ve olası kayıt tekrarını önlemek için koşula i==0 ilavesini yaptım
						{
							cout << "//KITAP BILGILERI" << endl
								<< "KITAP ISBN............................:" << ISBN_kitap << endl
								<< "KITAP ISMI............................:" << kitap_isim << endl
								<< "YAZAR ADI.............................:" << yazar_adi << endl
								<< "YAZAR SOYADI..........................:" << yazar_soyadi << endl
								<< "KITAP KONUSU..........................:" << konu << endl
								<< "KITAP TURU............................:" << tur << endl
								<< "SAYFA SAYI............................:" << sayfa_sayi << endl;
							kosul++;//kosul değerinin 1 arttırılması kullanıcının girdiği ISBN numarasına uygun kitabın bulunduğu demektir
							cout << "KITAP BILGIERINI DUZELTMEK ICIN DEVAM EDIN" << endl;
							cout << "KITAP ISBN............................:"; cin >> ISBN_kitap;
							cout << "KITAP ISMI............................:"; cin >> kitap_isim;
							cout << "YAZAR ADI.............................:"; cin >> yazar_adi;
							cout << "YAZAR SOYADI..........................:"; cin >> yazar_soyadi;
							cout << "KITAP KONUSU..........................:"; cin >> konu;
							cout << "KITAP TURU............................:"; cin >> tur;
							cout << "SAYFA SAYI............................:"; cin >> sayfa_sayi;
							dongu_onle++;//döngü bitene kadar bu if koşuluna maksimum 1 kez girilmesini sağlamak amacıyla i değeri 1 arttırılır 
							DosyaYaz << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " "
								<< tur << " " << sayfa_sayi << "\n";//kullanıcının girdiği güncel değerler kayd edilir
							gecici = ISBN_kitap;//bir sonraki döngüde ve alttaki if döngüsünde ISBN numaraları aynı olan kitapların kaydını önlemek için ISBN_kitap değişkenin değiri gecici değişkeninde tutulur
						}
						if (ISBN_kitap != gecici)//her 2 kitabın ISBN numarası farklıysa koşulun içine girer
						{
							DosyaYaz << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//verileri kayd eder
							gecici = ISBN_kitap; //bir sonraki döngüde ISBN numaraları aynı olan kitapların kaydını önlemek için ISBN_kitap değişkenin değiri gecici değişkeninde tutulur
						}
					}
					if (kosul == 0)//kitap
					{
						cout << "BU ISBN NUMARASI KAYITLI DEGIL, YENIDEN DENEYIN" << endl;//duruma uygun mesaj ekrana cıkarılır
					}
					else
					{
						cout << "* * * * * * KITAP DUZELTME BASARILI * * * * * *" << endl;
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove("kitap.txt");
					rename("kopyala.tmp", "kitap.txt");
				}
				else
				{
					cout << "BU KITAP DAHA GERI DONDURULMEDI. ISLEM YAPILAMAZ" << endl;
				}
				islem = 1;
				tekrar = -1;
			}
			else
			{
				if (tekrar > 1)
				{
					cout << "DOGRU SECİM YAPMADINIZ " << tekrar - 1 << " YANLIS YAPMA HAKKINIZ KALDI" << endl;//kullanıcı yanlış secim yaptığında kaç hakkı kaldığı ekrana yazılır
				}
			}
			/*------------ODÜNÇ ALMA VE KİTAP DÖNDÜRME İŞLEMİ BİTTİKTEN SONRA BU KOŞUL HER ZAMAN ÇALIŞIR-------------*/
			if (islem_1 != 0)//kitap ödünç aldıktan sonra okuyucunun kitap alma limitini 1 azaltıyor---------------------
			{
				kosul = 0;
				ifstream DosyaOku_1("okuyucu.txt");
				ofstream DosyaYaz_1("kopya.tmp");
				string gecici = "*";
				while (DosyaOku_1.eof() == 0)
				{
					DosyaOku_1 >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_alınabilir;//değerler dosyadan alınır
					if (degisecek == okuyucu_TC && gecici != okuyucu_TC)
					{
						if (kitap_alınabilir > 0 && islem_1 == 1)
						{
							kitap_alınabilir = kitap_alınabilir - 1;//kitap_alınabilir değişkeni 1 azaltılır
						}
						if (islem_1 == 2)
						{
							kitap_alınabilir = kitap_alınabilir + 1;
						}
						DosyaYaz_1 << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " " << tel
							<< " " << uye_numarasi << " " << gorev << " " << kitap_alınabilir << "\n";//ve yeniden kayd edilir
						kosul++;
						gecici = okuyucu_TC;
					}
					int i = 0;
					if (okuyucu_TC != gecici)
					{
						if (degisecek != okuyucu_TC)//geri kalan okuyucu kayıtları değiştirilmeden kayd edilir
						{
							DosyaYaz_1 << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " " << tel << " " << uye_numarasi << " " << gorev << " " << kitap_alınabilir << "\n";
						}
						gecici = okuyucu_TC;
					}
				}
				islem_1 = 0;
				DosyaYaz_1.close();
				DosyaOku_1.close();
				remove("okuyucu.txt");
				rename("kopya.tmp", "okuyucu.txt");
			}
			if (islem != 0 && tekrar == (-1))//kullanıcı yaptığı iş bittikten sonra çalışan if döngüsü
			{
				char cevap;
				cout << endl << "BASKA BIR SEY YAPACAK MISIN?(e/h).....:"; cin >> cevap;
				if (cevap == 'e' || cevap == 'E')
				{
					system("cls");
					menu();
					tekrar = 4;//cevap=e olduğunda en distaki for dongusunun eski hale gelmesini saglamak icin tekrar eski degerine yani 4'e esitlenir
					islem = 0;//islem degeri de eski haline dondurulur
				}
				else
				{
					system("cls");
				}
				cout << endl;
			}
		}
		if (tekrar == 0)//tekrar "0" a esitse hic bir islem yapilmadi demektir. kullanicinin yaptigi secim yanlistir
		{
			system("cls");
			cout << "YANLIS SECIM YAPTINIZ LUTFEN PROGRAMI YENIDEN BASLATIN" << endl;
			//ekran temizlenir ve uygun mesaj yazdirilir
		}
	}
	else
		cout << endl << "GIRDIGINIZ KULLANICI BILGILERI KAYITLI DEGILDIR" << endl;
	return 0;
}
