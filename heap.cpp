#include <iostream>

#define N 32

using namespace std;


void troca(int *a, int *b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

void criaHeap(int v[], int n, int i){
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if(esq < n && v[esq] > v[maior]){
        maior = esq;
    }

    if(dir < n && v[dir] > v[maior]){
        maior = dir;
    }

    if(maior != i){
        troca(&(v[i]), &(v[maior]));

        criaHeap(v, n, maior);
    }
}

void imprimeArvore(int v[], int n, int i, int level){
    if(i < n){

        imprimeArvore(v, n, (2*i+2), level+1);
        cout << string(level * 5, ' ') << v[i] << endl;
        //cout << string(level * 4, ' ') << "|-- " << v[i] << endl;
        imprimeArvore(v, n, (2*i+1), level+1);
    }
}

void heapSort(int v[], int n){
    for(int i = n - 1; i > 0; i--){
        
        cout << "Organiza em Heap:" << endl << endl;
        imprimeArvore(v, i+1, 0, 1);
        cout << endl << "------------------------------------------------------" << endl << endl;
        
        cout << "Troca os valores " << v[0] << " e " << v[i] << ":" << endl << endl;
        troca(&(v[0]), &(v[i]));
        imprimeArvore(v, i+1, 0, 1);
        cout << endl << "------------------------------------------------------" << endl << endl;
        
        cout << "Remove o " << v[i] << ":" << endl << endl;
        imprimeArvore(v, i, 0, 1);
        cout << endl << "------------------------------------------------------" << endl << endl;
        
        criaHeap(v, i, 0);
    }
}

int main(){
    int v[N];
    int x, n = 0;
    
    //adicniona valores ao vetor
    cout << "Adiciona valores inteiros ao Heap, ate ler o valor 0" << endl;
    
    while(cin >> x && x != 0){
        v[n] = x;
        n++;
    }

    cout << "Heap organizado em arvore:" << endl;
    imprimeArvore(v, n, 0, 1);
    cout << "------------------------------------------------------" << endl
    << "Processo do HeapSort" << endl << endl;
    
    for(int i = n / 2 - 1; i >= 0; i--)
        criaHeap(v, n, i);

    heapSort(v, n);
    
    cout << "Vetor Organizado {";
    for(int i = 0; i < n; i++){
        cout << v[i];
        if(i < n-1)
            cout << ", ";
    }
    cout <<"}" << endl << endl;

    cout << "Arvore do Heap:" << endl << endl;
    imprimeArvore(v, n, 0, 1);
}
