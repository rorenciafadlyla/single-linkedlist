#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

// node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void tranverse(node *head);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void cariData(node **head);
void jumlahData(node **head);
void totalData(node **head);

//========================================================

int main()
{
    node *head;
    int pilih;

    head = NULL;
    do
    {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir list \n");
        printf("4. Cetak isi list\n");
        printf("5. Hapus data di awal\n");
        printf("6. Hapus data ditengah list\n");
        printf("7. Hapus data di akhir list\n");
        printf("8. Cari data didalam list\n");
        printf("9. Jumlah data didalam list\n");
        printf("10. Hasil penjumlahan semua data dalam list\n");

        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf("%d", &pilih);
        if (pilih == 1)
            tambahAwal(&head);
        else if (pilih == 2)
            tambahData(&head);
        else if (pilih == 3)
            tambahAkhir(&head);
        else if (pilih == 4)
        {
            tranverse(head);
            getch();
        }
        else if (pilih == 5)
            hapusAwal(&head);
        else if (pilih == 6)
            hapusData(&head);
        else if (pilih == 7)
            hapusAkhir(&head);
        else if (pilih == 8)
            cariData(&head);
        else if (pilih == 9)
            jumlahData(&head);
        else if (pilih == 10)
            totalData(&head);

    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head)
{
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL)
    {
        pNew->data = bil;
        pNew->next = NULL;
        pNew->next = *head;
        *head = pNew;
    }
    else
    {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head)
{
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos)
    {
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL)
    {
        printf("\nNode tidak ditemukan");
        getch();
    }
    else if (pNew == NULL)
    {
        printf("\nAlokasi memeori gagal");
        getch();
    }
    else
    {
        pNew->data = bil;
        pNew->next = NULL;
        pNew->next = pCur->next;
        pCur->next = pNew;
    }
}

//========================================================

void tambahAkhir(node **head)
{
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("Masukkan sebuah bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL)
    {
        pNew->data = bil;
        pNew->next = NULL;

        if (*head == NULL)
        {
            *head = pNew;
        }
        else
        {

            pCur = *head;
            while (pCur->next != NULL)
            {
                pCur = pCur->next;
            }

            pCur->next = pNew;
        }
    }
    else
    {
        printf("\nAlokasi memori gagal");
        getch();
    }
}

//========================================================

void tranverse(node *head)
{
    // traverse a linked list
    node *pWalker;

    system("cls");
    pWalker = head;
    while (pWalker != NULL)
    {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
        printf(" -> ");
    }
    printf("NULL");
}

//========================================================

void hapusAwal(node **head)
{
    node *pCur;
    if (*head == NULL)
    {
        printf("List kosong\n");

        getch();
    }
    else
    {
        pCur = *head;
        *head = (*head)->next;
        free(pCur);
        printf("\nData berhasil dihapus");
        getch();
    }
}
//========================================================

void hapusData(node **head)
{
    int bil;
    node *pCur, *pPre;

    system("cls");
    tranverse(*head);
    printf("\nBilangan :  ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    pPre = NULL;

    while (pCur != NULL && pCur->data != bil)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL)
    {
        printf("\ndata tidak ditemukan");
        getch();
        return;
    }

    if (pPre == NULL)
    {
        *head = pCur->next;
    }
    else
    {
        pPre->next = pCur->next;
    }
    free(pCur);
    printf("\ndata berhasil dihapus");
    getch();
}

//========================================================

void hapusAkhir(node **head)
{
    node *pCur, *pPre;
    if (*head == NULL)
    {
        printf("\nlist kosong");
        getch();
        return;
    }

    pCur = *head;
    pPre = NULL;
    while (pCur->next != NULL)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    if (pPre == NULL)
    {
        *head = pCur->next;
    }
    else
    {
        pPre->next = NULL;
    }

    free(pCur);
    printf("\ndata berhasil dihapus");
    getch();
}

//========================================================

void cariData(node **head)
{
    int target, index = 0;
    node *pCur, *pPre;

    system("cls");
    fflush(stdin);
    printf("masukkan angka yang dicari: ");
    fflush(stdin);
    scanf("%d", &target);

    if (*head == NULL)
    {
        printf("\nlist kosong");
        getch();
        return;
    }

    pCur = *head;
    pPre = NULL;

    while (pCur != NULL)
    {
        if (pCur->data == target)
        {
            printf("\ndata %d ditemukan pada index : %d ", target, index);
            getch();
        }

        pCur = pCur->next;
        index++;
    }

    printf("\ndata tidak ditemukan");
    getch();
}

//========================================================

void jumlahData(node **head)
{
    int count = 0;
    node *pCur;
    if (*head == NULL)
    {
        printf("\nlist kosong");
        getch();
        return;
    }

    pCur = *head;

    while (pCur != NULL)
    {
        count++;
        pCur = pCur->next;
    }

    printf("jumlah data dalam list adalah %d ", count);
    getch();
}

//========================================================

void totalData(node **head)
{
    int total;
    node *pCur;

    if (*head == NULL)
    {
        printf("\nList kosong");
        getch();
    }

    pCur = *head;

    while (pCur != NULL)
    {
        total += pCur->data;
        pCur = pCur->next;
    }

    printf("Total penjumlahan data dalam list adalah %d ", total);
    getch();
}