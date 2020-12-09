#include <iostream>
using std::cout;
using std::cin;
using std::endl;
char  place[3][3]={{' ',' ',' '},
                   {' ',' ',' '},
                   {' ',' ',' '}};

void field(){
  cout<<"Поле:"<<endl;
  for (int i=0; i<3;++i){
    for(int j =0;j<3;++j){
      cout <<"-"<<place[i][j]<<"-";
      if(j == 2){
        cout<<endl;
      }else{cout<<"|";}
    }
  }
}

bool winner(){
  int s = 0;
  bool sym = false;
  for (int i=0; i<3;++i){
    for(int j =0;j<3;++j){
      if (place[i][j] !=' '){s+=1;}
    }
  }
  for(int j=0;j<3;++j){
    if(place[j][0]==place[j][1] &&
    place[j][1]==place[j][2] && 
  (place[j][1] != ' ')){
      field();
      cout<<"Выиграл "<<place[j][0];
      sym = true;
      break;
    }
  } 
  for(int i=0;i<3;++i){
    if(place[0][i]==place[1][i] && 
    place[1][i]==place[2][i] && 
  (place[1][i] != ' ')){
      field();
      cout<<"Выиграл "<<place[0][i];
      sym = true;
      break;
    }
  }
  if((place[0][0]==place[1][1] &&
  place[1][1]==place[2][2]) && 
  (place[1][1] != ' ')){
    field();
    cout<<"Выиграл "<<place[1][1];
    sym = true;
  }else 
  if(place[0][2]==place[1][1] &&
  place[1][1]==place[2][0] && 
  (place[1][1] != ' ')){
    field();
    cout<<"Выиграл "<<place[1][1];
    sym = true;
  }else 
  if (s == 9){
    field();
    cout<<"Ничья"<<endl;
    sym = true;
  } 
  return sym;
};

bool step(char sym){
  cout<<"Ведите номер клетки: "<<endl;
  cout<<"(0) (1) (2)"<<endl;
  cout<<"(3) (4) (5)"<<endl;
  cout<<"(6) (7) (8)"<<endl;
  int num;
  bool li=0, fil;
  while(li == false){
    cin>>num;
    
    if((place[num/3][num%3] == ' ')&&((num<9) && (num>=0))){
      place[num/3][num%3] = sym;
      li = 1;
      fil=winner();
    }
    else if((num>=9) || (num<0)){
      cout<<"Вы ввели недопустимое значение. Повторите попытку."<<endl;
    }
    else{
      cout<<
      "Это поле занято. Введите другой номер."
      <<endl;
    }
  }
  return fil;
};


bool game(int k){
  bool sym;
  field();
  
  if(k%2==0){
    cout<<"Ход X. ";
    sym = step('X');
    return sym;
  }else{
    cout<<"Ход O. ";
    sym = step('O');
    return sym;
    }
}

int main(){
  int k = 0;
  bool play=0;
  while(play == false){
    play = game(k);
    k+=1;
  }
}
