#include <iostream>
using namespace std;

class node{
public:
    char data;
    node* berikut;
    node* sebelum;
    node(char data){
        this -> data = data;
        this -> berikut = nullptr;
        this -> sebelum = nullptr;
    }
};

class doubleLinkedList{
private:
    node* pertama;
    node* terakhir;
public:
    doubleLinkedList(){
        pertama = nullptr;
        terakhir = nullptr;
    }

    void displayForward(){
        cout << "\nDari pertama ke terakhir\n";
        node* ptrData = pertama;
        while (ptrData!=nullptr){
            cout << ptrData -> data ;
            ptrData = ptrData -> berikut;
        }
        cout << endl;
    }

    void displayBackward(){
        cout << "Dari terakhir ke pertama\n";
        node* ptrData = terakhir;
        while (ptrData!=nullptr){
            cout<< ptrData -> data ;
            ptrData = ptrData -> sebelum;
        }
        cout << endl;
    }

    void insertFirst(char data){
        node* ptrBaru = new node(data);
        if(pertama == nullptr ){
            terakhir = ptrBaru;
        } else {
            pertama -> sebelum = ptrBaru;
        }
        ptrBaru -> berikut = pertama;
        ptrBaru -> sebelum = nullptr ;
        pertama = ptrBaru;
        printf("\n %c telah ditambahkan di awal", data);
        
    }

    void insertLast(char data){
        node* ptrBaru = new node(data);
        if(pertama == nullptr){
            pertama = ptrBaru;
        } else {
            terakhir -> berikut = ptrBaru;
        }
        ptrBaru -> sebelum = terakhir;
        ptrBaru -> berikut = nullptr;
        terakhir = ptrBaru;
        printf("\n%c telah ditambahkan di akhir", data);
    }

    void insertAfter(char kunci, char data){
        node* ptrData = pertama;
        while(ptrData && ptrData -> data != kunci){
            ptrData = ptrData -> berikut;
        }
        if(ptrData == nullptr){
            cout << "data tidak ditemukan" << endl;
        }
        node* ptrBaru = new node(data);
        if(ptrData == terakhir){
            terakhir = ptrBaru;
        } else {
            ptrBaru -> berikut = ptrData -> berikut;
            ptrData -> berikut-> sebelum = ptrBaru;
        }
        ptrBaru -> sebelum = ptrData;
        ptrData -> berikut = ptrBaru;
        printf("\n%c telah ditambahkan setelah %c.", data,kunci);
    }

    void deletionFirst(){
        if(pertama == nullptr){
            cout << "Linkedlist kosong" << endl;
            return;
        }
        node* ptrData = pertama;
        if(pertama -> berikut==nullptr){
            terakhir = nullptr;
        } else {
            pertama -> berikut -> sebelum = nullptr;
        }
        pertama = pertama -> berikut;
        cout << "\nData di awal telah dihapus." << endl;
        delete ptrData;
    }

    void deletionLast(){
        if(pertama == nullptr){
            cout << "Linkedlist kosong" << endl;
            return;
        }
        node* ptrData = terakhir;
        if(pertama -> berikut==nullptr){
            pertama = nullptr;
        } else {
            terakhir -> sebelum -> berikut = nullptr;
        }
        terakhir = terakhir -> sebelum;
        cout << "\nData di akhir telah dihapus." << endl;
        delete ptrData;
    }

    bool deletionKey(char data) {
        node* ptrData = pertama;
        while (ptrData && ptrData->data != data) {
            ptrData = ptrData->berikut;
        }
        if (ptrData == nullptr) {
            return false;
        }
        if (ptrData == pertama) {
            pertama = ptrData->berikut;
        } else {
            ptrData->sebelum->berikut = ptrData->berikut;
        }
        if (ptrData == terakhir) {
            terakhir = ptrData->sebelum;
        } else {
            ptrData->berikut->sebelum = ptrData->sebelum;
        }
        printf("Data %c telah dihapus.\n", data);
        delete ptrData;
        return true;
    }
};


int main() {
    doubleLinkedList dll;

    while (true) {
        cout << "\n1. Sisipkan di awal" << endl;
        cout << "2. Sisipkan di akhir" << endl;
        cout << "3. Sisipkan setelah node tertentu" << endl;
        cout << "4. Hapus di awal" << endl;
        cout << "5. Hapus di akhir" << endl;
        cout << "6. Hapus node tertentu" << endl;
        cout << "7. Tampilkan" << endl;
        cout << "8. Keluar" << endl;
        string pilihan;
        cout << "Masukan pilihan anda: ";
        cin >> pilihan;
        if (isdigit(pilihan[0])) {
            int pilihan_int = stoi(pilihan);
            if (1 <= pilihan_int && pilihan_int <= 8) {
                if (pilihan_int == 1) {
                    char data;
                    cout << "Enter data: ";
                    cin >> data;
                    dll.insertFirst(data);
                } else if (pilihan_int == 2) {
                    char data;
                    cout << "Enter data: ";
                    cin >> data;
                    dll.insertLast(data);
                } else if (pilihan_int == 3) {
                    char key;
                    cout << "Enter the node: ";
                    cin >> key;
                   char data;
                    cout << "Enter a new data: ";
                    cin >> data;
                    dll.insertAfter(key, data);
                } else if (pilihan_int == 4) {
                    dll.deletionFirst();
                } else if (pilihan_int == 5) {
                    dll.deletionLast();
                } else if (pilihan_int == 6) {
                    char data;
                    cout << "Enter the node: ";
                    cin >> data;
                    dll.deletionKey(data);
                } else if (pilihan_int == 7) {
                    dll.displayForward();
                    dll.displayBackward();
                } else if (pilihan_int == 8) {
                    break;
                }
            } else {
                cout << "Pilih angka antara 1 - 8." << endl;
            }
        } else {
            cout << "Tolong masukan angka." << endl;
        }
    }
    return 0;
}
