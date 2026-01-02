#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// -----------------------------
// Class Film
// -----------------------------
class Film {
    string judul, jam;
    int harga;
    vector<vector<bool> > kursi;
public:
    Film(string j, string t, int h, int r, int c) {
        judul = j; jam = t; harga = h;
        kursi = vector<vector<bool> >(r, vector<bool>(c, false));
    }
    string getJudul(){ return judul; }
    string getJam(){ return jam; }
    int getHarga(){ return harga; }

    void tampilkanKursi() {
        cout << "\nLayout kursi " << judul << " (" << jam << ")\n";
        for(int i=0;i<kursi.size();i++){
            for(int j=0;j<kursi[i].size();j++)
                cout << (kursi[i][j] ? "X " : "O ");
            cout << endl;
        }
    }
    bool pesan(int r,int c){
        if(r>=0 && r<kursi.size() && c>=0 && c<kursi[0].size() && !kursi[r][c]){
            kursi[r][c]=true; return true;
        }
        return false;
    }
};

// -----------------------------
// Class Penonton
// -----------------------------
class Penonton {
    string nama;
public:
    Penonton(string n){ nama=n; }
    string getNama(){ return nama; }
};

// -----------------------------
// Class Bioskop
// -----------------------------
class Bioskop {
    vector<Film> daftar;
public:
    void tambahFilm(Film f){ daftar.push_back(f); }
    void tampilkanFilm(){
        cout << "\n=== DAFTAR FILM ===\n";
        for(int i=0;i<daftar.size();i++)
            cout << i+1 << ". " << daftar[i].getJudul()
                 << " (" << daftar[i].getJam() << ") Rp" << daftar[i].getHarga() << endl;
    }
    void pesanTiket(int idx, Penonton p, int r, int c){
        if(idx>=0 && idx<daftar.size() && daftar[idx].pesan(r,c)){
            time_t now=time(NULL);
            cout << "\n--- STRUK ---\n";
            cout << "Penonton : " << p.getNama() << endl;
            cout << "Film     : " << daftar[idx].getJudul() << " (" << daftar[idx].getJam() << ")\n";
            cout << "Kursi    : (" << r << "," << c << ")\n";
            cout << "Bayar    : Rp" << daftar[idx].getHarga() << endl;
            cout << "Tanggal  : " << ctime(&now);
        } else cout << "Kursi tidak tersedia!\n";
    }
    void tampilkanLayout(int idx){
        if(idx>=0 && idx<daftar.size()) daftar[idx].tampilkanKursi();
    }
};

// -----------------------------
// Main Program
// -----------------------------
int main(){
    Bioskop b;
    b.tambahFilm(Film("Avengers","19:00",50000,5,6));
    b.tambahFilm(Film("Spiderman","21:00",45000,5,6));

    b.tampilkanFilm();
    Penonton p1("Adi");

    b.pesanTiket(0,p1,2,3);
    b.tampilkanLayout(0);

    return 0;
}

