#include<iostream>
#define loop(n) for(int i=0; i<n; i++)
#include<climits>
using namespace std;

void swap_var(int &x, int &y){
  int temp = x;
  x = y;
  y = temp;
}

class minHeap{
  protected:
    int *arr;
    int size;
    int maxi;
  public:
    minHeap(){};
    minHeap(int maxi);
    void merge(int );
    int parent(int i) return (i-1)/2; 
    int left(int i) return (2*i + 1); 
    int right(int i)  return (2*i + 2); 
    int delete_Min();
    void key_decrease(int i, int new_x);
    int getMin()  return arr[0]; 
    void key_increase(int k);
};

minHeap::minHeap(int x){
  size = 0;
  maxi = x;
  arr = new int[x];
}

void minHeap::key_increase(int k){
  if (size == maxi){
    cout << "\nNo Space\n";
    return;
  }
  size++;
  int i = size - 1;
  arr[i] = k;
  while (i != 0 && arr[parent(i)] > arr[i]){
    swap_var(&arr[i], &arr[parent(i)]);
    i = parent(i);
  }
}

void minHeap::key_decrease(int i, int new_x){
  arr[i] = new_x;
  while (i != 0 && arr[parent(i)] > arr[i]){
    swap_var(&arr[i], &arr[parent(i)]);
    i = parent(i);
  }
}

int minHeap::delete_Min(){
  arr[0]=arr[size-1];
  size--;
  merge(0);
}

void minHeap::merge(int i){
  int l = left(i);
  int r = right(i);
  int temp = i;
  if (l < size && arr[l] < arr[i])
    temp = l;
  if (r < size && arr[r] < arr[temp])
    temp = r;
  if (temp != i){
    swap_var(&arr[i], &arr[temp]);
    merge(temp);
  }
}

class PQ:public minHeap{
  public:
    PQ(){};
    PQ(int x){
      size = 0;
      maxi =x;
      arr = new int[x];
    }
  void push(int x){
    key_increase(x);
  }
  int top(){
    return getMin();
  }
  void pop(){
    delete_Min();
  }
};

int main(){
  int toc,xxx,k;
  PQ heap(10000);
  cout<<"Enter the number of chocolates";
  cin>>toc;
  cout<<"Enter the values of chocolates:\n";
  loop(toc){
    cin>>xxx;
    heap.push(-xxx);
  }
  int x=0;
  cout<<"\nK= ";
  cin>>k;
  loop(k){
    int a=heap.top();
    x=x+a;
    heap.pop();
    heap.push(int(a/2));
  }
  cout<<(-x)<<"\n";
  return 0;
}
