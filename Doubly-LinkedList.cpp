#include <iostream> // Standart girdi ve çıktı işlemleri için gerekli kütüphaneyi ekler.

#include <string> // string veri türünü kullanabilmek için gerekli kütüphaneyi ekler.

using namespace std; // std ön ekini yazmadan standart kütüphane üyelerini kullanmayı sağlar.

struct DNode{ // Çift yönlü bağlı listenin düğüm yapısını tanımlar.
    int data; // Düğümde tutulacak tamsayı veriyi tanımlar.

    DNode* prev; // Önceki düğümü gösterecek işaretçiyi tanımlar.
    DNode* next; // Sonraki düğümü gösterecek işaretçiyi tanımlar.
}; // DNode yapısının tanımını sonlandırır.

void basaEkle(DNode*& head, int veri){ // Listenin başına yeni bir düğüm ekleyen fonksiyonu tanımlar.
    DNode* yeni = new DNode(); // Bellekte yeni bir düğüm oluşturur.
    yeni->data = veri; // Yeni düğümün verisini parametre olarak gelen değerle doldurur.
    yeni -> prev = nullptr; // Yeni düğümün önceki düğümünü boş olarak ayarlar.
    yeni->next = nullptr; // Yeni düğümün sonraki düğümünü boş olarak ayarlar.

    if (head != nullptr) // Liste boş değilse mevcut ilk düğümü kontrol eder.
        head->prev = yeni; // Mevcut ilk düğümün önceki bağlantısını yeni düğüme yönlendirir.
        head = yeni; // Listenin baş işaretçisini yeni düğümü gösterecek şekilde günceller.
    } // Başa ekleme fonksiyonunun kod bloğunu sonlandırır.

    void sonaEkle(DNode*& head, int veri){ // Listenin sonuna yeni bir düğüm ekleyen fonksiyonu tanımlar.
        DNode* yeni = new DNode(); // Bellekte yeni bir düğüm oluşturur.
        yeni->data = veri; // Yeni düğümün verisini parametre olarak gelen değerle doldurur.
        yeni->next = nullptr; // Yeni düğümün sonraki bağlantısını boş olarak ayarlar.
        if (head == nullptr){ // Liste boşsa bu durumu kontrol eder.
            yeni-> prev = nullptr; // İlk düğümün önceki bağlantısını boş olarak ayarlar.
            head = yeni; // Listenin baş işaretçisini yeni düğümü gösterecek şekilde ayarlar.
            return; // Fonksiyonu burada sonlandırır.
            
        } // Listenin boş olma durumuna ait kod bloğunu sonlandırır.

        DNode* temp = head; // Listenin başından ilerlemek için geçici işaretçi oluşturur.
        while (temp-> next != nullptr) // Listenin son düğümüne ulaşılmadığı sürece döngüyü sürdürür.
        temp = temp-> next; // Geçici işaretçiyi bir sonraki düğüme ilerletir.
        temp -> next = yeni; // Mevcut son düğümün sonraki bağlantısını yeni düğüme bağlar.
        yeni -> prev = temp; // Yeni düğümün önceki bağlantısını mevcut son düğüme bağlar.
    } // Sona ekleme fonksiyonunun kod bloğunu sonlandırır.

    void listeYazdir(DNode* head){ // Listeyi baştan sona yazdıran fonksiyonu tanımlar.
        DNode* temp = head; // Listenin başından ilerlemek için geçici işaretçi oluşturur.
        while (temp != nullptr){ // Listenin sonuna ulaşılmadığı sürece döngüyü sürdürür.
            cout << temp -> data << " "; // Geçerli düğümün verisini ekrana yazdırır.
            temp = temp->next; // Geçici işaretçiyi bir sonraki düğüme ilerletir.
        } // Liste üzerinde gezinme döngüsünü sonlandırır.

        cout << endl; // Çıktıda bir sonraki satıra geçer.
    } // Listeyi yazdırma fonksiyonunun kod bloğunu sonlandırır.
    
    void terstenYazdir(DNode* head){ // Listeyi sondan başa doğru yazdıran fonksiyonu tanımlar.
        if(head == nullptr) return; // Liste boşsa fonksiyonu hiçbir işlem yapmadan sonlandırır.
        DNode* temp = head; // Listenin başından ilerlemek için geçici işaretçi oluşturur.
        while (temp->next != nullptr) // Son düğüme ulaşılmadığı sürece döngüyü sürdürür.
        temp = temp->next; // Geçici işaretçiyi bir sonraki düğüme ilerletir.
        while(temp != nullptr){ // Listenin başına ulaşılmadığı sürece geriye doğru ilerler.
            cout << temp->data <<" "; // Geçerli düğümün verisini ekrana yazdırır.
            temp = temp->prev; // Geçici işaretçiyi önceki düğüme ilerletir.
        } // Tersten gezinme döngüsünü sonlandırır.
        cout << endl; // Çıktıda bir sonraki satıra geçer.
    } // Tersten yazdırma fonksiyonunun kod bloğunu sonlandırır.

    void bellekTemizle(DNode*& head){ // Listedeki tüm düğümleri bellekten silen fonksiyonu tanımlar.
        while(head != nullptr){ // Listede silinecek düğüm kaldığı sürece döngüyü sürdürür.
            DNode* sil = head; // Silinecek mevcut ilk düğümü geçici işaretçide tutar.
            head = head->next; // Liste başını bir sonraki düğüme taşır.
            delete sil; // Geçici işaretçinin gösterdiği düğümü bellekten siler.

        } // Bellek temizleme döngüsünü sonlandırır.
    } // Bellek temizleme fonksiyonunun kod bloğunu sonlandırır.

    int main(){ // Programın çalışmaya başladığı ana fonksiyonu tanımlar.
        DNode* head = nullptr; // Listenin başlangıç işaretçisini boş olarak oluşturur.
        int n, veri; // Eleman sayısını ve girilecek veriyi tutacak değişkenleri tanımlar.
        cout << "Kac eleman eklemek istersiniz? : "; // Kullanıcıdan eklenecek eleman sayısını ister.
        cin >> n; // Kullanıcının girdiği eleman sayısını okur.
        for(int i = 0; i < n; i++){ // Belirtilen eleman sayısı kadar döngüyü tekrarlar.
            cout << i+1 << ". elemani giriniz : "; // Sıradaki elemanın değerini kullanıcıdan ister.
            cin >> veri; // Kullanıcının girdiği değeri veri değişkenine aktarır.
            sonaEkle(head, veri); // Girilen değeri listenin sonuna ekler.

        } // Eleman ekleme döngüsünü sonlandırır.

        cout << "Bastan sona : "; // Listenin baştan sona yazdırılacağını belirtir.
        listeYazdir(head); // Listeyi baştan sona ekrana yazdırır.
        
        cout << "Sondan basa : "; // Listenin sondan başa yazdırılacağını belirtir.
        terstenYazdir(head); // Listeyi sondan başa ekrana yazdırır.

        bellekTemizle(head); // Program bitmeden listenin kullandığı belleği serbest bırakır.
        return 0; // Programın başarıyla sonlandığını işletim sistemine bildirir.
        
    } // Ana fonksiyonun kod bloğunu sonlandırır.
