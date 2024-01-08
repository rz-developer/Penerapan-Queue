#include <iostream>
#define MAX 16 //maksimum data queue (antrian)
using namespace std;

struct Queue {
	int head; 
	int tail; 
	int data[MAX];
}
Q;


bool isFull() {
	return Q.tail == MAX;
}


bool isEmpty() {
	return Q.tail == 0;
}


void printQueue() {
	if (isEmpty()) {
    cout << "Antrian Kosong"<<endl;
	}
	else {
		cout << "QUEUE : ";
		for (int i = Q.head; i < Q.tail; i++)
			cout << Q.data[i] << ((Q.tail-1 == i) ? "" : ",");
		cout << endl;
  }
}


void enqueue() {
	if (isFull())
	{
		cout << "Antrian Penuh"<<endl;
	}
	else {
		int data;
		cout << "Masukkan Data yang Diinginkan : ";cin >> data;
		Q.data[Q.tail] = data;
		Q.tail++;
		cout << "Data Berhasil Ditambahkan\n";
		printQueue();
	}
}


void dequeue() {
	if (isEmpty())
	{
		cout << "Antrian Kosong"<<endl;
	}
	else{
		cout << "Mengambil Data \"" << Q.data[Q.head] << "\"..." << endl;
		for (int i = Q.head; i < Q.tail; i++)
			Q.data[i] = Q.data[i + 1];
		Q.tail--;
		printQueue();
	}
}

int main() {
	int choose;
	do
	{
		cout << "=========QUEUE (ANTRIAN)=========\n"
			<< " 1. Tambahkan Data Ke Antrian \n"
			<< " 2. Mengambil Data Dari Antrian \n"
			<< " 3. Keluar \n"
			<< "==================================\n"
			<< "Masukkan Pilihan : "; cin >> choose;
		switch (choose)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		default:
			cout << "Pilihan Tidak Tersedia";
			break;
		}
	} while (choose !=3);
	return 0;
}
