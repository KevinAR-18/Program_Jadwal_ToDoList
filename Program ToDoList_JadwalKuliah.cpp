#include <iostream>  // Header Library umum untuk C++.
#include <string> 	// Header Library string.
#include <conio.h>	// Header Libray untuk getch.
#include <unistd.h> // Header Library agar dapat menggunakan delay (sleep).
#include <fstream>	// Header Library untuk operasi file.
using namespace std; // Untuk menggunakan fungsi standar.
void header(); 		// Baris ke-7 hingga ke-22 mendeklarasikan fungsi yang digunakan pada program.
void garis();   		
void garis_2();  
void menu_1();
void menu_2();
void menu_3();
void menu_4();
void ubahjadwal();
void jadwaltabel();
void space();
void cetak_jadwal();
void cetak_tugas();
void todolist();
void showtodo();
void keterangan();
void keterangan_2();

int pil_1,pil_2,pil_3,nomor; // Mendelkarasikan variabel bertipe data integer.

string todo [11][3]={{"1.", "-----------","-------"},{"2.", "-----------","-------"},  // Mendeklarasikan Array untuk to do list dengan tipe data string.
{"3.", "-----------","-------"},{"4.", "-----------","-------"},{"5.", "-----------","-------"},{"6.", "-----------","-------"}, //Juga menyatakan isi array.
{"7.", "-----------","-------"},{"8.", "-----------","-------"},{"9.", "-----------","-------"},{"10.", "-----------","-------"}};

string jadwal [11][5]= {{"No", "Mata Kuliah", "		Hari", " Jam ", "       Ruang Kelas"}, // Mendeklarasikan Array untuk jadwal dengan tipe data string.
	{"1.","Bahasa Inggris 1	", "Kamis", "14.15 - 15.55", "CU207"},							// Juga menyatakan isi array.
	{"2.","Elektronika Analog	", "Selasa", "07.15 - 08.55", "CU206"},
	{"3.","Matematika Teknik 1	", "Rabu", "07.15 - 08.55", "CU206"},
	{"4.","Praktikum Desain Elektronik"	, "Senin", "12.15 - 15.55", "HS207"},
	{"5.","Praktikum Gambar Teknik	", "Kamis ", "07.15 - 10.55", "HU106"},
	{"6.","Praktikum Pemograman Dasar", "Rabu ", "12.15 - 15.55", "CU101"},
	{"7.","Praktikum Teknik Instrumentasi", "Senin", "07.15 - 10.55", "HS206"},
	{"8.","Rangkaian Listrik DC	", "Jumat", "13.00 - 14.40", "CU207"},
	{"9.","Teknik Instrumentasi	", "Selasa", "09.15 - 10.55", "CU204"},
	{"10.","Fisika Teknik 1		", "Rabu", "09.15 - 10.55", "CU205"}};

int main(){ // Fungsi int main, sebagai fungsi utama program.
	do{     // perulangan do while untuk kembali halaman awal program ketika pada menu 2 dan menu 3 memilih kembali.
	do{		// perulangan do while untuk kembali halaman awal program saat salah input pada menu awal.
	header(); // Memanggil fungsi header yang berisi Judul program.
	menu_1(); // Memanggil fungsi menu 1.
	if(pil_1==1){ //Masuk ke Program Jadwal.
		do { // perulangan do untuk kembali kehalaman menu jadwal.
		jadwaltabel(); // Memanggil fungsi jadwaltabel untuk menampilkan jadwal.
		space();  // Memberikan jeda pada console.
		menu_2();  // Berisi menu 2.
		if (pil_2==1){  // Menjalankan isi if ketika memilih program ubah jadwal.
			system("cls"); // Membersihkan layar console. 
			jadwaltabel(); 
			space();
			menu_3(); // Memanggil fungsi menu 3.
			ubahjadwal(); // Memanggil fungsi ubahjadwal.
			pil_2=4; //Menyatakan nilai variabel agar dapat menjalankan do while.
		} else if (pil_2==2){
			space();
			cetak_jadwal(); // Memanggil fungsi cetak_jadwal untuk membuat file txt
			pil_2=4;
		} else if (pil_2==3){
			system("cls");
		} else {
			cout << "Ulangi Input! Masukan Angka 1-3! " << endl; //perintah cout untuk menampilkan kalimat.
			sleep(3); //perintah sleep untuk memberikan delay selama 3 detik pada program.
		} }while (pil_2>3); 
		
	} else if(pil_1==2){ //Masuk ke Program To Do List.
		do { // perulangan do while untuk kembali menu to do list.
		showtodo(); // Memanggil fungsi showtodo untuk menampilkan daftar to do list.
		space();
		menu_4(); //Memanggil fungsi menu 4
		if (pil_3==1){
			system("cls");
			showtodo();
			space();
			menu_3();
			todolist();
			pil_3=4; //Menyatakan nilai variabel agar dapat menjalankan do while.
		} else if (pil_3==2){
			space();
			cetak_tugas(); // Memanggil fungsi cetak_tugas untuk membuat file txt
			pil_3=4;
		} else if (pil_3==3){
			pil_2=3;
			system("cls");
		} else {
			cout << "Ulangi Input! Masukan Angka 1-3! " << endl; //perintah cout untuk menampilkan kalimat.
			sleep(3); //perintah sleep untuk memberikan delay selama 3 detik pada program.
		} }while (pil_3>3); //
		
		
	} else if(pil_1==3){  // Menjalankan kodisi saat program selesai.
		system ("cls");
		cout << "Program Selesai" << endl;
		return 0; // 
	} else {  // Menjalankan kondisi ketika salah input
		cout << "Ulangi Input! Masukan Angka 1-3! " << endl; 
		sleep(3);
		system("cls");
	} }while (pil_1>3) ; // do while akan berjalan ketika pil_1>3 dan merupakan kondisi saat salah input.
	} while (pil_2==3); // do while akan berjalan ketika pil_2=3 dan merupakan kondisi saat ingin kembali ke menu utama.
	
}
void header(){ // Menyatakan Isi dari fungsi header.
	garis(); // Memanggil fungsi garis.  
	cout << "|Program Jadwal dan To-do List|" << endl;  // Perintah cout untuk membuat tampilan awal program.
	cout << "|-----------------------------|" << endl;
	cout << "|Program UAS Pemograman Dasar |" << endl;
	cout << "|	Kelompok 2	      |" << endl;
	garis(); 
	space(); // Memanggil fungsi space.
}
void garis(){ // Menyatakan Isi dari fungsi garis
cout << "===============================" << endl; //Perintah cout untuk membuat garis pembatas.
}
void garis_2(){ // Menyatakan isi dari fungsi garis_2
for (int j=0; j<75; j++){  // Menggunakan perulangan for loop untuk membuat garis pembatas.
			cout << "~";
		} cout << endl;
}
void space(){ // Menyatakan isi dari fungsi space.
	cout << endl;  //Perintah cout endl untuk memberikan jeda 1 baris pada program.
}
void menu_1(){ // Menyatakan isi dari fungsi menu_1.
	cout << "1. Jadwal Kuliah" << endl;   // Perintah cout untuk membuat tampilan menu 1 pada program.
	cout << "2. To Do List" << endl;
	cout << "3. Keluar" << endl;
	cout << "\nMasukan Pilihan (1-3): ";
	cin >> pil_1; // Perintah cin untuk menginput nilai ke variabel. Input dilakukan oleh user.
}
void jadwaltabel(){ // Menyatakan isi dari fungsi jadwaltabel.
	system ("cls");
	cout << "Jadwal Kuliah" << endl;
	garis_2();
		for (int i=0; i<11; i++){  // Perulangan for loop untuk membuat tampilan tabel jadwal.
		for (int j=0; j<5; j++){
			cout << jadwal [i][j] <<"	";
		} cout << "" << endl;
	}
	garis_2();
}
void menu_2(){ // Menyatakan isi dari fungsi menu_2.
	cout << "1. Ubah Jadwal" << endl; // Perintah cout untuk membuat tampilan menu 2 pada program.
	cout << "2. Cetak Jadwal (.txt)" << endl;
	cout << "3. Kembali" << endl;
	cout << "\nMasukan Pilihan (1-3): ";
	cin >> pil_2; // Perintah cin untuk menginput nilai ke variabel. Input dilakukan oleh user.
}
void menu_3(){
	cout << "Pilih No yang ingin di ubah"<< endl; // Perintah cout untuk membuat tampilan menu 3 pada program.
	cout << "==========================="<< endl; 
	cout << "\nMasukan Pilihan (1-10): ";
	cin >> nomor; // Perintah cin untuk menginput nilai ke variabel. Input dilakukan oleh user.
}
void ubahjadwal(){ // Menyatakan isi dari fungsi ubahjadwal.
	switch (nomor){ // Pengkondisian switch case, terdapat 10 case dan default case.
		case 1:      // Berisi case 1.
			system("cls");                          // Case 1 berisi perintah untuk input data ke array jadwal.
			cout << "Ubah Isi Tabel " << endl;
			garis();
			keterangan();  		// Memanggil fungsi keterangan.
			cin.ignore();		// Berfungsi mengabaikan karakter yang ada pada input streams.
			cout << "\nMasukan Mata Kuliah: ";
			getline (cin,jadwal[1][1]);	// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Hari: ";
			getline (cin,jadwal[1][2]);
			cout << "Masukan Jam: ";
			getline (cin,jadwal[1][3]);
			cout << "Masukan Ruang: ";
			getline (cin,jadwal[1][4]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch(); // Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;		// Untuk menghindari eksekusi pada case dibawahnya.
		case 2: 	// Berisi case 2.
			system("cls");
			cout << "Ubah Isi Tabel " << endl;
			garis();
			cin.ignore(); // Berfungsi mengabaikan karakter yang ada pada input streams.
			keterangan();
			cout << "\nMasukan Mata Kuliah: ";
			getline (cin,jadwal[2][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Hari: ";
			getline (cin,jadwal[2][2]);
			cout << "Masukan Jam: ";
			getline (cin,jadwal[2][3]);
			cout << "Masukan Ruang: ";
			getline (cin,jadwal[2][4]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();
			break;		// Untuk menghindari eksekusi pada case dibawahnya.	
		case 3:		// Berisi case 3.
			system("cls");
			cout << "Ubah Isi Tabel " << endl;
			garis();
			cin.ignore(); // Berfungsi mengabaikan karakter yang ada pada input streams.
			keterangan();
			cout << "\nMasukan Mata Kuliah: ";
			getline (cin,jadwal[3][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Hari: ";
			getline (cin,jadwal[3][2]);
			cout << "Masukan Jam: ";
			getline (cin,jadwal[3][3]);
			cout << "Masukan Ruang: ";
			getline (cin,jadwal[3][4]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;		// Untuk menghindari eksekusi pada case dibawahnya.	
		case 4:				// Berisi case 4.
			system("cls");
			cout << "Ubah Isi Tabel " << endl;
			garis();
			cin.ignore(); // Berfungsi mengabaikan karakter yang ada pada input streams.
			keterangan();
			cout << "\nMasukan Mata Kuliah: ";
			getline (cin,jadwal[4][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Hari: ";
			getline (cin,jadwal[4][2]);
			cout << "Masukan Jam: ";
			getline (cin,jadwal[4][3]);
			cout << "Masukan Ruang: ";
			getline (cin,jadwal[4][4]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;		// Untuk menghindari eksekusi pada case dibawahnya.	
		case 5:				// Berisi case 5.
			system("cls");
			cout << "Ubah Isi Tabel " << endl;
			garis();
			cin.ignore(); // Berfungsi mengabaikan karakter yang ada pada input streams.
			keterangan();
			cout << "\nMasukan Mata Kuliah: ";
			getline (cin,jadwal[5][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Hari: ";
			getline (cin,jadwal[5][2]);
			cout << "Masukan Jam: ";
			getline (cin,jadwal[5][3]);
			cout << "Masukan Ruang: ";
			getline (cin,jadwal[6][4]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;		// Untuk menghindari eksekusi pada case dibawahnya.	
		case 6:					// Berisi case 6.
			system("cls");
			cout << "Ubah Isi Tabel " << endl;
			garis();
			cin.ignore(); // Berfungsi mengabaikan karakter yang ada pada input streams.
			keterangan();
			cout << "\nMasukan Mata Kuliah: ";
			getline (cin,jadwal[6][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Hari: ";
			getline (cin,jadwal[6][2]);
			cout << "Masukan Jam: ";
			getline (cin,jadwal[6][3]);
			cout << "Masukan Ruang: ";
			getline (cin,jadwal[6][4]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;		// Untuk menghindari eksekusi pada case dibawahnya.
		case 7:				// Berisi case 7.
			system("cls");
			cout << "Ubah Isi Tabel " << endl;
			garis();
			cin.ignore(); // Berfungsi mengabaikan karakter yang ada pada input streams.
			keterangan();
			cout << "\nMasukan Mata Kuliah: ";
			getline (cin,jadwal[7][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Hari: ";
			getline (cin,jadwal[7][2]);
			cout << "Masukan Jam: ";
			getline (cin,jadwal[7][3]);
			cout << "Masukan Ruang: ";
			getline (cin,jadwal[7][4]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;		// Untuk menghindari eksekusi pada case dibawahnya.
		case 8:				// Berisi case 8.
			system("cls");
			cout << "Ubah Isi Tabel " << endl;
			garis();
			cin.ignore(); // Berfungsi mengabaikan karakter yang ada pada input streams.
			keterangan();
			cout << "\nMasukan Mata Kuliah: ";
			getline (cin,jadwal[8][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Hari: ";
			getline (cin,jadwal[8][2]);
			cout << "Masukan Jam: ";
			getline (cin,jadwal[8][3]);
			cout << "Masukan Ruang: ";
			getline (cin,jadwal[8][4]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;	// Untuk menghindari eksekusi pada case dibawahnya.
		case 9:					// Berisi case 9.
			system("cls");
			cout << "Ubah Isi Tabel " << endl;
			garis();
			cin.ignore(); // Berfungsi mengabaikan karakter yang ada pada input streams.
			keterangan();
			cout << "\nMasukan Mata Kuliah: ";
			getline (cin,jadwal[9][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Hari: ";
			getline (cin,jadwal[9][2]);
			cout << "Masukan Jam: ";
			getline (cin,jadwal[9][3]);
			cout << "Masukan Ruang: ";
			getline (cin,jadwal[9][4]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;		// Untuk menghindari eksekusi pada case dibawahnya.
		case 10:				// Berisi case 10.
			system("cls");
			cout << "Ubah Isi Tabel " << endl;
			garis();
			cin.ignore(); // Berfungsi mengabaikan karakter yang ada pada input streams.	
			keterangan();
			cout << "\nMasukan Mata Kuliah: ";
			getline (cin,jadwal[10][1]);	// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Hari: ";
			getline (cin,jadwal[10][2]);
			cout << "Masukan Jam: ";
			getline (cin,jadwal[10][3]);
			cout << "Masukan Ruang: ";
			getline (cin,jadwal[10][4]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break; 		// Untuk menghindari eksekusi pada case dibawahnya.
		default: 		// Berisi default case 
			cout << "Ulangi Input! Masukan Angka 1-10! " << endl;
			sleep(2);	 				 
	}
}
void cetak_jadwal(){ // Menyatakan isi dari fungsi cetak_jadwal
	ofstream myFile("jadwal_kuliah.txt"); //Menyatakan variabel myFile dengan tipe data ofstream. Juga membuat file jadwal_kuliah.txt.
	
	string matkul[10];		//Menyatakan array dengan variabel string.
	string hari[10];
	string jam[10];
	string kelas[10];
	// Baris 353-396 berguna untuk mengelompokan isi array sesuai dengan namanya, sehingga mempermudah ketika menginput ke file txt.
	matkul[0] = jadwal[1][1];  //Menyatakan bahwa isi array matkul = array jadwal pada index sesuai disamping.
	matkul[1] = jadwal[2][1];
	matkul[2] = jadwal[3][1];
	matkul[3] = jadwal[4][1];
	matkul[4] = jadwal[5][1];
	matkul[5] = jadwal[6][1];
	matkul[6] = jadwal[7][1];
	matkul[7] = jadwal[8][1];
	matkul[8] = jadwal[9][1];
	matkul[9] = jadwal[10][1];
	
	hari[0] = jadwal[1][2];	//Menyatakan bahwa isi array hari = array jadwal pada index sesuai disamping.
	hari[1] = jadwal[2][2];
	hari[2] = jadwal[3][2];
	hari[3] = jadwal[4][2];
	hari[4] = jadwal[5][2];
	hari[5] = jadwal[6][2];
	hari[6] = jadwal[7][2];
	hari[7] = jadwal[8][2];
	hari[8] = jadwal[9][2];
	hari[9] = jadwal[10][2];
	
	jam[0] = jadwal[1][3];	//Menyatakan bahwa isi array jam = array jadwal pada index sesuai disamping.
	jam[1] = jadwal[2][3];	
	jam[2] = jadwal[3][3];
	jam[3] = jadwal[4][3];
	jam[4] = jadwal[5][3];
	jam[5] = jadwal[6][3];
	jam[6] = jadwal[7][3];
	jam[7] = jadwal[8][3];
	jam[8] = jadwal[9][3];
	jam[9] = jadwal[10][3];
	
	kelas[0] = jadwal[1][4];	//Menyatakan bahwa isi array kelas= array jadwal pada index sesuai disamping.
	kelas[1] = jadwal[2][4];
	kelas[2] = jadwal[3][4];
	kelas[3] = jadwal[4][4];
	kelas[4] = jadwal[5][4];
	kelas[5] = jadwal[6][4];
	kelas[6] = jadwal[7][4];
	kelas[7] = jadwal[8][4];
	kelas[8] = jadwal[9][4];
	kelas[9] = jadwal[10][4];


	myFile << "\nJadwal ";	//Perintah myFile << untuk memasukan kalimat atau suatu nilai ke variabel nilai dan di simpan pada file txt.
	myFile << "\n========================================================";
	myFile << "\nNo	Matakuliah			Hari	 Jam		Kelas" << endl;
	myFile << "1.	" << matkul[0] << "	" << hari[0] << "	" << jam[0] << "	" << kelas[0] << endl;
	myFile << "2.	" << matkul[1] << "	" << hari[1] << "	" << jam[1] << "	" << kelas[1] << endl;
	myFile << "3.	" << matkul[2] << "	" << hari[2] << "	" << jam[2] << "	" << kelas[2] << endl;
	myFile << "4.	" << matkul[3] << "	" << hari[3] << "	" << jam[3] << "	" << kelas[3] << endl;
	myFile << "5.	" << matkul[4] << "	" << hari[4] << "	" << jam[4] << "	" << kelas[4] << endl;
	myFile << "6.	" << matkul[5] << "	" << hari[5] << "	" << jam[5] << "	" << kelas[5] << endl;
	myFile << "7.	" << matkul[6] << "	" << hari[6] << "	" << jam[6] << "	" << kelas[6] << endl;
	myFile << "8.	" << matkul[7] << "	" << hari[7] << "	" << jam[7] << "	" << kelas[7] << endl;
	myFile << "9.	" << matkul[8] << "	" << hari[8] << "	" << jam[8] << "	" << kelas[8] << endl;
	myFile <<"10.	" << matkul[9] << "	" << hari[9] << "	" << jam[9] << "	" << kelas[9] << endl;
	myFile.close(); 		// Perintah untuk menutup my.File.
	
	system("cls"); // Berguna untuk membersihkan layar
	cout << "Tunggu Sebentar..."<< endl;
	sleep(2); // Berguna untuk memberikan delay 2 detik.
	cout << "Silakan Cek File Anda, Jadwal sudah menjadi file txt" << endl;
	cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
	getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
}
void menu_4(){ // Menyatakan isi fungsi menu_4
	cout << "1. Tambahkan Daftar Tugas" << endl;  //Perintah cout untuk menampilkan kalimat.
	cout << "2. Cetak Daftar Tugas (.txt)" << endl;
	cout << "3. Kembali" << endl;
	cout << "\nMasukan Pilihan (1-3): ";
	cin >> pil_3;		// Perintah cin untuk menginput nilai ke variabel. Input dilakukan oleh user.
}
void todolist(){ // Menyatakan isi fungsi todolist.
	switch (nomor){ // Pengkondisian switch case, terdapat 10 case dan default case.
		case 1:  //Berisi case 1.
			system("cls");
			cout << "Ubah Isi To Do List " << endl;
			garis();		//Memanggil fungsi garis.
			cin.ignore();	// Berfungsi mengabaikan karakter yang ada pada input streams.	
			keterangan_2();		// Memanggil fungsi keterangan_2.
			cout << "\nMasukan To Do List: ";
			getline (cin,todo[0][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Deadline: ";
			getline (cin,todo[0][2]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;
		case 2:		//Berisi case 2.
			system("cls");
			cout << "Ubah Isi To Do List " << endl;
			garis();
			cin.ignore();	// Berfungsi mengabaikan karakter yang ada pada input streams.	
			keterangan_2();
			cout << "\nMasukan To Do List: ";
			getline (cin,todo[1][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Deadline: ";
			getline (cin,todo[1][2]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;		
		case 3:		//Berisi case 3.
			system("cls");
			cout << "Ubah Isi To Do List " << endl;
			garis();
			cin.ignore();		// Berfungsi mengabaikan karakter yang ada pada input streams.	
			keterangan_2();
			cout << "\nMasukan To Do List: ";
			getline (cin,todo[2][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Deadline: ";
			getline (cin,todo[2][2]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;		
		case 4:		//Berisi case 4.
			system("cls");
			cout << "Ubah Isi To Do List " << endl;
			garis();
			cin.ignore();		// Berfungsi mengabaikan karakter yang ada pada input streams.	
			keterangan_2();
			cout << "\nMasukan To Do List: ";
			getline (cin,todo[3][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Deadline: ";
			getline (cin,todo[3][2]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;		
		case 5:			//Berisi case 5.
			system("cls");
			cout << "Ubah Isi To Do List " << endl;
			garis();
			cin.ignore();		// Berfungsi mengabaikan karakter yang ada pada input streams.	
			keterangan_2();
			cout << "\nMasukan To Do List: ";
			getline (cin,todo[4][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Deadline: ";
			getline (cin,todo[4][2]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;		
		case 6:		//Berisi case 6.
			system("cls");
			cout << "Ubah Isi To Do List " << endl;
			garis();
			cin.ignore();		// Berfungsi mengabaikan karakter yang ada pada input streams.	
			keterangan_2();
			cout << "\nMasukan To Do List: ";
			getline (cin,todo[5][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Deadline: ";
			getline (cin,todo[5][2]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;			
		case 7:		//Berisi case 7.
			system("cls");
			cout << "\nUbah Isi To Do List " << endl;
			garis();
			cin.ignore();		// Berfungsi mengabaikan karakter yang ada pada input streams.	
			keterangan_2();
			cout << "Masukan To Do List: ";
			getline (cin,todo[6][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Deadline: ";
			getline (cin,todo[6][2]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;		
		case 8:		//Berisi case 8.
			system("cls");
			cout << "Ubah Isi To Do List " << endl;
			garis();
			cin.ignore();		// Berfungsi mengabaikan karakter yang ada pada input streams.	
			keterangan_2();
			cout << "\nMasukan To Do List: ";
			getline (cin,todo[7][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Deadline: ";
			getline (cin,todo[7][2]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();	// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;
		case 9:			//Berisi case 9.
			system("cls");
			cout << "Ubah Isi To Do List " << endl;
			garis();
			cin.ignore();		// Berfungsi mengabaikan karakter yang ada pada input streams.	
			keterangan_2();
			cout << "\nMasukan To Do List: ";
			getline (cin,todo[8][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Deadline: ";
			getline (cin,todo[8][2]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();		// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;
		case 10:		//Berisi case 10.
			system("cls");
			cout << "Ubah Isi To Do List " << endl;
			garis();
			cin.ignore();		// Berfungsi mengabaikan karakter yang ada pada input streams.	
			keterangan_2();   
			cout << "\nMasukan To Do List: ";
			getline (cin,todo[9][1]);		// Perintah getline untuk menginput string ke ke array. Input dilakukan oleh user.
			cout << "Masukan Deadline: ";
			getline (cin,todo[9][2]);
			garis();
			cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
			getch();		// Berguna untuk meminta input enter dan dapat menjeda program hingga user menekan enter.
			break;
		default: //Berisi default case.
			cout << "Ulangi Input! Masukan Angka 1-10! " << endl;
			sleep(2);	//Memberikan delay pada program selama 2 detik.				 
	}
	}
void showtodo(){	// Menyatakan isi fungsi showtodo.
	system ("cls");
	cout << "Daftar Tugas/ To Do List" << endl;
	garis_2();  // Memanggil fungsi garis_2.
	cout << "No	Keterangan			Deadline" << endl;
		for (int i=0; i<10; i++){		//Perulangan for loop untuk menampilkan tampilan daftar tugas/to do list.
		for (int j=0; j<3; j++){
			cout << todo [i][j] <<"	";
		} cout << endl;
	}
	garis_2();
	}
void cetak_tugas(){ // Menyatakan isi fungsi cetak_tugas.
	ofstream myFile("Daftar_Tugas.txt");	//Menyatakan variabel myFile dengan tipe data ofstream. Juga membuat file "daftar_tugas.txt".
	
	string keterangan[10];	//Menyatakan array dengan variabel string.
	string deadline[10];
	// Baris 592-613 berguna untuk mengelompokan isi array sesuai dengan namanya, sehingga mempermudah ketika menginput ke file txt.
	keterangan[0] = todo[0][1];		//Menyatakan bahwa isi array keterangan = array todo pada index sesuai disamping.
	keterangan[1] = todo[1][1];
	keterangan[2] = todo[2][1];
	keterangan[3] = todo[3][1];
	keterangan[4] = todo[4][1];
	keterangan[5] = todo[5][1];
	keterangan[6] = todo[6][1];
	keterangan[7] = todo[7][1];
	keterangan[8] = todo[8][1];
	keterangan[9] = todo[9][1];
	
	deadline[0] = todo[0][2];		//Menyatakan bahwa isi array deadline = array todo pada index sesuai disamping.
	deadline[1] = todo[1][2];
	deadline[2] = todo[2][2];
	deadline[3] = todo[3][2];
	deadline[4] = todo[4][2];
	deadline[5] = todo[5][2];
	deadline[6] = todo[6][2];
	deadline[7] = todo[7][2];
	deadline[8] = todo[8][2];
	deadline[9] = todo[9][2];
	
	myFile << "\nJadwal ";		//Perintah myFile << untuk memasukan kalimat atau suatu nilai ke variabel nilai dan di simpan pada file txt.
	myFile << "\n========================================================";
	myFile << "\nNo	Keterangan			Deadline" << endl;
	myFile << "1.	" << keterangan[0] << "	" << deadline[0] << endl;
	myFile << "2.	" << keterangan[1] << "	" << deadline[1] << endl;
	myFile << "3.	" << keterangan[2] << "	" << deadline[2] << endl;
	myFile << "4.	" << keterangan[3] << "	" << deadline[3] << endl;
	myFile << "5.	" << keterangan[4] << "	" << deadline[4] << endl;
	myFile << "6.	" << keterangan[5] << "	" << deadline[5] << endl;
	myFile << "7.	" << keterangan[6] << "	" << deadline[6] << endl;
	myFile << "8.	" << keterangan[7] << "	" << deadline[7] << endl;
	myFile << "9.	" << keterangan[8] << "	" << deadline[8] << endl;
	myFile <<"10.	" << keterangan[9] << "	" << deadline[9] << endl;
	myFile.close(); // Perintah untuk menutup my.File.
	
	system("cls");
	cout << "Tunggu Sebentar..."<< endl;
	sleep(2);
	cout << "Silakan Cek File Anda, Jadwal sudah menjadi file txt" << endl;
	cout << "Tekan Enter untuk kembali ke menu sebelumnya..";
	getch();
}
void keterangan(){ // Menyatakan isi fungsi keterangan yang berisi perintah cout untuk menapilkan kalimat.
	cout << "Ket: - Setelah Mengetik Mata Kuliah klik TAB agar dapat memberikan spasi sehingga tabel dapat rapi."<< endl;
	cout << "- Jika panjang frasa/kata pendek klik TAB 1-3 kali. Jika panjang frasa/kata panjang maka tidak perlu klik TAB" << endl;
	cout << "- Pastikan penulisan format sesuai dengan tabel sebelumnya." << endl;
	cout << "- Format: Bahasa Inggris		Selasa    18.00 - 23.59  	CU209" << endl;
	garis(); // Memanggil fungsi garis.
}
void keterangan_2(){	// Menyatakan isi fungsi keterangan_2 yang berisi perintah cout untuk menapilkan kalimat.
	cout << "Ket: - Setelah Mengetik To Do List klik TAB agar dapat memberikan spasi sehingga tabel dapat rapi."<< endl;
	cout << "- Jika panjang kalimat pendek klik TAB 1-3 kali. Jika panjang kalimat panjang maka tidak perlu klik TAB" << endl;
	garis();	// Memanggil fungsi garis.
}	
