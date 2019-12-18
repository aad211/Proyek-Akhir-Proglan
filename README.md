# Proyek-Akhir-Proglan (SUPER MAKMAK)

## Latar Belakang

Jaman sekarang banyak orang tua terutama kaum ibu disepelekan karena pengetahuannya yang dibilang kurang update oleh banyak orang, padahal ibu-ibu adalah penguasa rumah dan jalanan yang sangat ditakuti pada jaman dahulu kala. Tujuan kita adalah membuat kaum ibu kembali dengan cara meminjam buku sebanyak-banyaknya karena buku adalah sumber ilmu, dengan maksud ibu-ibu tersebut tidak akan ketinggalan zaman jika tetap mengupdate pengetahuannya dengan banyak meminjam buku.


## Konsep

#### UI
Di dalam folder UI terdapat program yang berfungsi untuk menampilkan game dan memproses segala input dari user, lalu jika input yang diberikan user berupa kontrol di dalam game maka game akan berfungsi sebagaimana mestinya, jika user memberikan input pada kotak teks maka hasil dari inputan user tersebut akan diparsing ke program administrator untuk kemudian diolah dan disimpan datanya.

Jadi saat awal membuka game anda akan menemukan sedikit intro yang kemudian bisa lanjut bermain ke dalam game dengan menekan tombol apapun, kemudian di dalam game pemain dapat bergerak-gerak sampai menemui istana, saat bertemu istana pemain dapat memilih untuk memasuki istana *engan menekan tombol 'w'* untuk melihat-lihat buku atau lanjut bergerak ke depan untuk melawan musuh-musuh agar mendapatkan point. Selain dengan bermain, user juga dapat mendapatkan point dengan jumlah besar jika sudah berhasil meminjam buku serta telah selesai membacanya, user juga dapat mendapat point tambahan jika memberikan review dari buku yang telah dibacanya serta pesan dan kesan untuk pengembangan aplikasi ini kedepannya.

Lalu untuk masuk ke dalam istana maka user diwajibkan untuk melakukan login untuk bisa melanjutkan. Di dalam istana user akan menemukan sebuah komputer yang bisa berinteraksi *dengan menekan tombol 'w'* yang kemudian komputer tersebut akan memberikan tampilan input teks untuk user jika ingin mencari apakah buku tersebut tersedia dan dimana lokasi buku tersebut.

Jika sudah menentukan tujuan peminjaman maka user bisa melanjutkan game yang kemudian user bisa memilih akan meminjam buku dari rak sebelah mana, atau jika lupa dan jauh lokasi raknya user dapat memanggil peri untuk memberikan bantuannya, dengan menekan tombol 's' maka peri akan datang dan memberi menu pilihan untuk melihat dimana bukunya, atau membawa langsung ke tempat bukunya, atau user juga bisa mengobrol-ngobrol dengan peri tersebut.

Jika sudah menemukan raknya, maka di setiap rak user akan menemukan tokoh-tokoh khas dari rak tersebut yang ada di sekeliling rak tersebut *harus dengan cara manual mengubah tokohnya* lalu user dapat berinteraksi dengan rak tersebut *dengan menekan tombol 'w'* untuk kemudian memasuki rak tersebut untuk mencari buku apa yang ingin dipinjam *jika sudah menggunakan bantuan peri maka buku yang ingin dipinjam akan berada pada urutan paling pertama, jika terdapat lebih dari 1 buku yang dicari maka buku akan berurutan dari yang terakhir dicari sampai yang pertama dicari* jika sudah menemukan bukunya user dapat berinteraksi lagi *dengan menekan tombol 'w'* untuk meminjam buku tersebut.

Jika proses peminjaman berhasil maka buku akan terpinjam dan user dapat melakukan hal lain seperti membaca-baca sinopsis buku lain, atau meminjamnya, atau bahkan bermain gamenya dengan kembali ke titik masuk istana, kemudian berinteraksi dengan pintunya *dengan menekan tombol 'w'* kemudian user akan kembali ke scene awal.

Untuk melakukan pendaftaran, user diwajibkan untuk datang terlebih dahulu ke perpustakaan terdekat yang telah bekerja sama dengan kami supaya segala transaksi dapat dilakukan dengan aman.

#### Administrator
Jadi di dalam program yang ada di folder administrator berfungsi untuk memproses segala data yang diberikan oleh UI, proses yang dapat dilakukan melalui UI adalah melihat daftar-daftar buku/rak, meminjam buku, dan mengembalikan buku. Sedangkan fungsi yang hanya bisa diakses melalui aplikasi administrator adalah mendaftarkan akun, menambahkan buku/rak, menghapus buku/rak.


## Kontrol

D -> jalan ke kanan

S -> memanggil peri

A -> jalan ke kiri

W -> berinteraksi dengan sesuatu

Spasi -> lompat


## Kendala

Sampai saat ini UI yang dibuat masih sangat berkendala karena kurangnya waktu eksplorasi terhadap SDL sehingga sampai saat ini UI masih belum bisa menerima input teks yang diberikan user untuk kemudian diparsing ke fungsi administrator. Jadi saat ini program hanya bisa dijalankan dan melakukan fungsinya melalui program administrator saja.
