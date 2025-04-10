#include <stdio.h>
#include <time.h>

#define JUMLAH_BARANG 30

int stok[JUMLAH_BARANG] = {78, 90, 55, 70, 87, 56, 64, 86, 99, 40, 10, 20, 30, 40, 50, 60, 70, 80, 90, 11, 22, 33, 44, 55, 66, 77, 88, 99, 95, 75}; // Stok awal untuk setiap barang

int main() {
    char pembeli[50];
    int harga[JUMLAH_BARANG] = {200000, 100000, 150000, 170000, 70000, 65000, 30000, 120000, 90000, 79000, 130000, 99000, 40000, 110000, 50000, 80000, 73000, 9000, 34000, 105000, 20000, 76000, 115000, 88000, 140000, 19000, 160000, 87000, 20000, 35000}; // Harga untuk setiap barang
    int jumlah[JUMLAH_BARANG];
    int total, jumtotal, jumbayar, kembalian, potongan, grandTotal = 0;
    char input;
    char kode[3];

    while (2) {
        time_t now = time(0);
        struct tm *ltm = localtime(&now);

        printf("   	 TOKO KOSMETIK SID       \n");
        printf("=================================================\n");
        printf("Tanggal: %02d/%02d/%d ", ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year);
        printf("Jam: %02d:%02d:%02d\n", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
        printf("=================================================\n");
        printf("Nama Pembeli   : ");
        scanf("%s", pembeli);

        do {
        printf("Pilih Barang yang Tersedia\n");
        printf("=================================================\n");
        printf("01 - Lipstik - Rp.200.000 	(Stok: %d biji)\n", stok[0]);
        printf("02 - Pensil Alis - Rp.100.000 	(Stok: %d biji)\n", stok[1]);
        printf("03 - Foundation - Rp.150.000 	(Stok: %d biji)\n", stok[2]);
        printf("04 - Serum Wajah - Rp.170.000 	(Stok: %d biji)\n", stok[3]);
        printf("05 - Sunscreen - Rp.70.000 	(Stok: %d biji)\n", stok[4]);
        printf("06 - Maskara - Rp.65.000 	(Stok: %d biji)\n", stok[5]);
        printf("07 - Pewarna Rambut - Rp.30.000 (Stok: %d biji)\n", stok[6]);
        printf("08 - Face Wash - Rp.120.000 	(Stok: %d biji)\n", stok[7]);
        printf("09 - Sunblok - Rp.90.000 	(Stok: %d biji)\n", stok[8]);
        printf("10 - Blush On - Rp.79.000 	(Stok: %d biji)\n", stok[9]);
        printf("11 - Bedak Padat - Rp.130.000 	(Stok: %d biji)\n", stok[10]);
        printf("12 - Toner Wajah - Rp.99.000 	(Stok: %d biji)\n", stok[11]);
        printf("13 - Hair Removal - Rp.40.000 	(Stok: %d biji)\n", stok[12]);
        printf("14 - Eyeliner - Rp.110.000 	(Stok: %d biji)\n", stok[13]);
        printf("15 - Body Lotion - Rp.50.000 	(Stok: %d biji)\n", stok[14]);
        printf("16 - Pelembab Wajah - Rp.80.000 (Stok: %d biji)\n", stok[15]);
        printf("17 - Concleaner - Rp.73.000 	(Stok: %d biji)\n", stok[16]);
        printf("18 - Penghapus Riasan - Rp.9.000(Stok: %d biji)\n", stok[17]);
        printf("19 - Krim Mata - Rp.34.000 	(Stok: %d biji)\n", stok[18]);
        printf("20 - Scrub Wajah - Rp.105.000 	(Stok: %d biji)\n", stok[19]);
        printf("21 - Hand Cream - Rp.20.000 	(Stok: %d biji)\n", stok[20]);
        printf("22 - Pewarna Kuku - Rp.76.000 	(Stok: %d biji)\n", stok[21]);
        printf("23 - Hair Serum - Rp.115.000 	(Stok: %d biji)\n", stok[22]);
        printf("24 - Parfum - Rp.88.000 	(Stok: %d biji)\n", stok[23]);
        printf("25 - Setting Pray - Rp.140.000 	(Stok: %d biji)\n", stok[24]);
        printf("26 - Pengait Rambut - Rp.19.000 (Stok: %d biji)\n", stok[26]);
        printf("27 - Lip Liner - Rp.160.000 	(Stok: %d biji)\n", stok[26]);
        printf("28 - Bedak Tabur - Rp.87.000 	(Stok: %d biji)\n", stok[27]);
        printf("29 - Masker Wajah - Rp.20.000 	(Stok: %d biji)\n", stok[28]);
        printf("30 - Deodorant - Rp.35.000 	(Stok: %d biji)\n", stok[29]);
        printf("=================================================\n");

           // ...
			printf("Barang yang dipilih :");
			scanf("%2s", kode);
			// Membersihkan buffer input
			fflush(stdin);
			// Konversi kode menjadi indeks
			int indeksBarang = atoi(kode) - 1;
			// ...
            if (indeksBarang >= 0 && indeksBarang < JUMLAH_BARANG && stok[indeksBarang] > 0) {
                printf("Jumlah Beli         :");
                scanf("%d", &jumlah[indeksBarang]);

                // Periksa apakah jumlah pembelian melebihi stok
                if (jumlah[indeksBarang] > stok[indeksBarang]) {
                    printf("Maaf, stok tidak mencukupi.\n");
                    continue;
                } else {
                // Kurangi stok setelah pembelian
                stok[indeksBarang] -= jumlah[indeksBarang];
                // ...

				// Pengguna ingin menghapus barang dari pembelian
				printf("Ingin Menghapus Barang yang sudah dibeli? [Y/N] : ");
				scanf(" %c", &input);
				
				if (input == 'y' || input == 'Y') {
				    // Pengguna ingin menghapus barang, minta kode barang yang akan dihapus
				    printf("Masukkan kode barang yang ingin dihapus : ");
				    scanf("%2s", kode);
				
				    // Membersihkan buffer input
				    fflush(stdin);
				
				    // Konversi kode menjadi indeks
				    indeksBarang = atoi(kode) - 1;
				
				    // Periksa apakah kode barang yang dimasukkan valid
				    if (indeksBarang >= 0 && indeksBarang < JUMLAH_BARANG && jumlah[indeksBarang] > 0) {
				        // Tambahkan stok yang dihapus kembali ke stok awal
				        stok[indeksBarang] += jumlah[indeksBarang];
				
				        // Kurangi total belanja dan grandTotal
				        total = harga[indeksBarang] * jumlah[indeksBarang];
				        grandTotal -= total;
				
				        // Tampilkan informasi penghapusan barang
				        printf("Barang %s sejumlah %d berhasil dihapus dari pembelian.\n", kode, jumlah[indeksBarang]);
				    } else {
				        printf("Kode barang yang dimasukkan tidak valid atau barang tidak ada dalam pembelian.\n");
				    }
				}

					// Tampilkan struk pembayaran
					printf("=================================================\n");
					printf("Struk Pembayaran\n");
					printf("=================================================\n");
					printf("Nama Pembeli      :%s\n", pembeli);
					printf("Harga             :%d\n", harga[indeksBarang]);
					printf("Jumlah            :%d\n", jumlah[indeksBarang]);
					
					total = harga[indeksBarang] * jumlah[indeksBarang];
					
					printf("Total             :%d\n", total);
					
					// Diskon jika jumlah beli lebih dari 5
					if (jumlah[indeksBarang] > 5) {
					    potongan = 0.1 * total;  // Diskon 10%
					} else {
					    potongan = 0;
					}
					
					printf("Potongan          :%d\n", potongan);
					printf("=================================================\n");
					
					jumtotal = total - potongan;
					
					printf("Total Belanja     :%d\n", jumtotal);
					grandTotal += jumtotal;
					
					printf("Mau Tambah Pembelian Lagi? [Y/N] : ");
					scanf(" %c", &input);
					
					// ...
					
	                
            }
            } else {
                printf("Barang yang dipilih tidak tersedia atau stok habis.\n");
                continue;
            }

       } while (input == 'y' || input == 'Y');

        // Tampilkan total belanjaan sebelum pembelian kembali
        printf("Total Keseluruhan :%d\n", grandTotal);

        printf("Uang Bayar        :");
        scanf("%d", &jumbayar);

        kembalian = jumbayar - grandTotal;
        printf("Uang Kembalian    :%d\n", kembalian);
        printf("=================================================\n");

        // Tampilkan stok barang yang tersisa
        printf("Stok Barang Tersisa:\n");
        printf("01 - Lipstik		: %d biji\n", stok[0]);
        printf("02 - Pensil Alis	: %d biji\n", stok[1]);
        printf("03 - Foundation		: %d biji\n", stok[2]);
        printf("04 - Serum Wajah 	: %d biji\n", stok[3]);
        printf("05 - Sunscreen  	: %d biji\n", stok[4]);
        printf("06 - Maskara  		: %d biji\n", stok[5]);
        printf("07 - Pewarna Rambut 	: %d biji\n", stok[6]);
        printf("08 - Face Wash  	: %d biji\n", stok[7]);
        printf("09 - Sunblok  		: %d biji\n", stok[8]);
        printf("10 - Blush On  		: %d biji\n", stok[9]);
        printf("11 - Bedak Padat  	: %d biji\n", stok[10]);
        printf("12 - Toner Wajah  	: %d biji\n", stok[11]);
  		printf("13 - Hair Removal	: %d biji\n", stok[12]);
        printf("14 - Eyeliner 		: %d biji\n", stok[13]);
        printf("15 - Body Lotion 	: %d biji\n", stok[14]);
        printf("16 - Pelembab Wajah 	: %d biji\n", stok[15]);
        printf("17 - Concleaner 	: %d biji\n", stok[16]);
        printf("18 - Penghapus Riasan	: %d biji\n", stok[17]);
        printf("19 - Krim Mata 		: %d biji\n", stok[18]);
        printf("20 - Scrub Wajah 	: %d biji\n", stok[19]);
        printf("21 - Hand Cream 	: %d biji\n", stok[20]);
        printf("22 - Pewarna Kuku 	: %d biji\n", stok[21]);
        printf("23 - Hair Serum		: %d biji\n", stok[22]);
        printf("24 - Parfum 		: %d biji\n", stok[23]);
        printf("25 - Makeup Setting Pray: %d biji\n", stok[24]);
        printf("26 - Alat Pengait Rambut: %d biji\n", stok[26]);
        printf("27 - Lip Liner 		: %d biji\n", stok[26]);
        printf("28 - Bedak Tabur 	: %d biji\n", stok[27]);
        printf("29 - Masker Wajah 	: %d biji\n", stok[28]);
        printf("30 - Deodorant 		: %d biji\n", stok[29]);
		printf("=================================================\n");
        printf("Mau proses pembelian baru Lagi [Y/N] : ");
        
		scanf(" %c", &input);

        if (input != 'y' && input != 'Y') {
            break;
        }
    }

    printf("Total Keseluruhan Pembelian pada hari ini: %d\n", grandTotal);
    return 0;
}