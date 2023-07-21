#include<bits/stdc++.h>
#include<ctime>
#define ll long long int
using namespace std;

void PacketLostTransmission(){ //packet Lost 
  ll i=1;
  ll N,totalframe,totalsend=0;
  cout<<"Enter the Total Packets"<<endl;
  cin>>totalframe;

  cout<<"Enter The Window Size"<<endl;
  cin>>N;

  ll lost;
  cout<<"Enter the number of i'th Lost Packet"<<endl;
  cin>>lost;
  int count=0;
  while (i <= totalframe) {
    int z = 0;
    for (int k = i; k < i + N && k <= totalframe; k++) {
      cout << "Sending Packet " << k << "..." << endl;
      totalsend++;
      count++;
      //cout<<"COUNT IS "<<count<<endl;
      if(totalsend % lost == 0){
        cout<<"Packet number "<<k<<" Lost During Transmission"<<endl;
        cout<<"Retransmitting Packet"<<endl;
        cout << "Sending Frame " << k << "..." << endl;
        //cout<<totalsend<<endl;
        if(totalframe-count >= N){
          totalsend+=N;
        }
        else{
          totalsend+=totalframe-count+1;
        }
        
        cout<<totalsend<<endl;
      }
    }
    //int f = timeout;
    for (int k = i; k < i + N && k <= totalframe; k++) {
      cout << "Acknowledgment for Packet " << k << "..." << endl;
      z++;
    }
    cout << "\n";
    i = i + z;
  }
  cout<<"Total Packets Transmitted is: "<<totalsend<<endl;
}

void acknowledgementLost() {
  ll i=1;
  ll N,totalframe,totalsend=0;
  cout<<"Enter the Total Packets"<<endl;
  cin>>totalframe;

  cout<<"Enter The Window Size"<<endl;
  cin>>N;

  ll timeout;
  cout<<"Enter the TimeOut Time"<<endl;
  cin>>timeout;

  while (i <= totalframe) {
    int z = 0;
    for (int k = i; k < i + N && k <= totalframe; k++) {
      cout << "Sending Packet " << k << "..." << endl;
      totalsend++;
    }
    int f = timeout;
    for (int k = i; k < i + N && k <= totalframe; k++) {
      // cout<<f<<endl;
      // cout<<tt<<endl;
      if (f!=0) {
        cout << "Acknowledgment for Packet " << k << "..." << endl;
        z++;
        f--;
      }
       else {
        cout << "Timeout!! Frame Packet : " << k << " Not Received" << endl;
        cout << "Retransmitting Window..." << endl;
        break;
      }
    }
    cout << "\n";
    i = i + z;
  }
  cout<<"Total Packets Transmitted is: "<<totalsend<<endl;
}

int main() {

  while(1){
    
  ll choice;
  cout<<endl;
  cout<<"------------------------------------------------START------------------------------------------"<<endl;
  cout<<"Enter Choice of Packet Sending"<<endl;
  cout<<"1:For Condition Packet Lost\n2:For condition of Acknowledgement Lost\n3:To Exit"<<endl;
  cin>>choice;
  switch(choice){
    case 1:PacketLostTransmission();
    break;
    case 2:acknowledgementLost();
    break;
    case 3:exit(0);
    break;
    default:cout<<"Wrong choice Entered"<<endl;
    break;
  }
  cout<<"----------------------------------------------END--------------------------------------------"<<endl;
  }
}