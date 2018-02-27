/*##########�o�O�ƿW###########*/
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <ctime>
#include "Sudoku.h"
#include "data.h"
using namespace std;



Sudoku::Sudoku()
	:same(0)
{
	srand(time(NULL));
	InitBoard();
	FullSudoku();
	DigSudoku();
	equivalent();
	m_ans=0;
	SolveSudoku(Play);
	for(int i=0;i<M_MAX;i++)
	{
		if(Play[i]==Solve[i])
			same++;
	}
}


Sudoku::~Sudoku()
{}


void Sudoku::InitBoard()  // ���ͧ���ƿW�L��
{
    m_mid = (M_MAX+1)/2; 
	for(m_col = M_SIZE, m_row=2; m_row<m_col; m_row++)
		 if (M_SIZE%m_row==0) m_col=M_SIZE/m_row;
	 m_row = M_SIZE/m_col;
	 m_ans = 0;
	for(int i=0; i<M_SIZE*M_SIZE; i++)
		 Board[i]=0;
}


int Sudoku::Stuff(const int &p,const int &num)  //��J
{
  if (Board[p]!=0) return 0;  
  for(int i=0; i<M_SIZE; i++)
    if(Board[p/M_SIZE*M_SIZE+i]==num || Board[i*M_SIZE+p%M_SIZE]==num) return 0;
  Board[p]=num;  
  return 1;
}
 
void Sudoku::FullSudoku()
{
  int loc, re, i; 
  int pos[M_SIZE];
 
  for(i=0; i<M_SIZE*M_SIZE; i++) Board[i]=Solve[i]=0;
  for(i=0; i<M_SIZE; i++)
    pos[i] = i/m_col*M_SIZE+i%m_col;   // �p�c�椺���� 
  
  for(int num=1; num<=M_SIZE; num++)  // �w��J�Ʀr 
  {
    re = 0;      
    for(int block=0; block<M_SIZE; block++)  // �p�c�� 
    {
        loc = block/m_row*m_row*M_SIZE+block%m_row*m_col;  // �p�c���m 
        for(i=0; i<M_SIZE; i++)  // ���äp�c�椺����
        {
           int j = rand()%M_SIZE;
           int t = pos[i];  pos[i]=pos[j]; pos[j] = t;  //�洫     
        }        
        while(--i>=0 && !Stuff(loc+pos[i], num));  // ��J 
        if (i<0)
        {  // ��J���� -- �٭�Ҷ�Ʀr 
           for(int p=0; p<M_MAX; p++)
              if(Board[p]==num) Board[p]=0;           
           block = -1;   // ����~~ (��block�q0�}�l)
           if(++re>M_SIZE) break; // �Y���Ӧ��ƹL�h, ���� 
        }
    }
    if (re>M_SIZE) num-=2;  // �Y���Ӧ��ƹL�h, �h�^�e�@�Ʀr 
  } 
}


bool Sudoku::CheckEnd(int *b)
{
  int p, i, r, c, l, s;
  for(p=0; p<M_MAX; p++)
  {
    if (b[p]==0) return false;
    r=p/M_SIZE; c=p%M_SIZE;  l=r/m_row*m_row*M_SIZE+c/m_col*m_col;  // ��m���� 
    for(i=0; i<M_SIZE; i++)  //  �ˬd ��C�P�p�E�c���O�_���� 
    {
      s = l + i/m_col*M_SIZE+i%m_col;
      if((i!=c && b[r*M_SIZE+i]==b[p]) || ( i!=r && b[i*M_SIZE+c]==b[p])
         || ( s!=p && b[s]==b[p]) )  return false;  //�����Ыh���� 
    }
  }
  return true;
}

bool Sudoku::play()
{
	
	show(Play);
	cout<<"��J1~9���T�ӼƦr(���O���C�B��B��)\n��J0��delete\n��J�ucheck my answer�v�i�ˬd���׬O�_���T"<<endl;
	
	char *inputRow=new char [6];
	char *inputColumn=new char [6];
	char *inputValue=new char [6];

	fflush(stdin);  //�M�Žw�s��
	cin>>inputColumn>>inputRow>>inputValue;

	//������A�����ӧQ����
	if(strcmp(inputColumn,"show")==0 && strcmp(inputRow,"the")==0 && strcmp(inputValue,"answer")==0 )
	{
		show(Solve);
		cout<<"�ѵ��b��!\n"<<endl;
		cout<<"�t�δ���:\n\t\t";
		cout<<"��o40�U�٥�!!\n\n";
		money = money + 200000;
		system("pause");
		return true;
	}

	else if(strcmp(inputColumn,"check")==0 && strcmp(inputRow,"my")==0 && strcmp(inputValue,"answer")==0 )
	{
		if(same!=M_MAX)
		{
			cout<<"��"<<M_MAX-same<<"�ӼƦr����"
					<<"�A�ЦA�ˬd"<<endl;
			system("pause");
		}
		return false;
	}
	
	
	int inRow=0;
	int inColumn=0;
	int inValue=0;
	int judge=0;

	int RowLen=strlen(inputRow);
	int ColumnLen=strlen(inputColumn);
	int ValueLen=strlen(inputValue);

	int site;
	for(site=0;site<RowLen;site++)
	{
		if(inputRow[site]>=48 && inputRow[site]<=57)
			judge++;
	}
	for(site=0;site<ColumnLen;site++)
	{
		if(inputColumn[site]>=48 && inputColumn[site]<=57)
			judge++;
	}
	for(site=0;site<ValueLen;site++)
	{
		if(inputValue[site]>=48 && inputValue[site]<=57)
			judge++;
	}

	bool check=false;
	try
	{
		if(RowLen>6 || ColumnLen>6 || ValueLen>6)
		{
			throw"���׹L��";
		}

		else if(judge==(RowLen+ColumnLen+ValueLen)&&RowLen==1&&ColumnLen==1 && ValueLen==1)
		{
			inRow=atoi(inputRow);
			inColumn=atoi(inputColumn);
			inValue=atoi(inputValue);

			inRow--;
			inColumn--;
	
			if(Board[inRow*M_SIZE+inColumn]!=0)
			{
				throw "�D�ؤ��i���";
			}//end else if
			Play[inRow*M_SIZE+inColumn]=inValue;
		}//end if

		else if(judge!=(RowLen+ColumnLen+ValueLen) || RowLen!=1 || ColumnLen!=1 || ValueLen!=1)
		{
			throw "�п�J1~9���Ʀr";
		}//end else if
	}//end try
	catch(char *input)
	{
		cout<<input<<endl;
		system("pause");
	}//end catch

	same=0;
	for(int i=0;i<M_MAX;i++)
	{
		if(Play[i]==Solve[i])
			same++;
	}
	if(same==M_MAX)
	{
		cout<<"\n���ߧA�����F�I\n";
		system("pause");
		system("cls");
		cout<<"�t�δ���\n\t\t";
		cout<<"��o30�U�٥�!!\n\n";
		money = money + 300000;
		system("pause");
		check=true;
	}


	return check;
}//end Sudoku::play()


void Sudoku::show(int *map) const
{
	system("cls");

	int site;
	cout<<" ";
	for(site=1;site<=M_SIZE;site++)
		cout<<setw(5)<<site;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); //������j�u
	cout<<"\n   ============================================="<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

	for(site=0;site<M_MAX;site++)
	{
		
		if(site%9==0)
		{
			cout<<" "<<site/9+1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//������j�u
			cout<<"�x ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			if(map[site]==0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);//�¦�
				cout<<map[site];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}//end else
			else if(map[site]!=Board[site])
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);//���
				cout<<map[site];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}
			else
				cout<<map[site];
		}//end if

		else if(site%9==8)
		{
			if((site+1)%27==0)
			{
				cout<<setw(5);
				if(map[site]==0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);//�¦�
					cout<<map[site];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				}//end else
				else if(map[site]!=Board[site])
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);//���
					cout<<map[site];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				}
				else
					cout<<map[site];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); //������j�u
				cout<<" �x\n   ============================================="<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}
			else
			{
				cout<<setw(5);
				if(map[site]==0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);//�¦�
					cout<<map[site];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				}//end else
				else if(map[site]!=Board[site])
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);//���
					cout<<map[site];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				}
				else
					cout<<map[site];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//������j�u
				cout<<" �x\n  �x------------�x-------------�x--------------�x"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}
		}//end else if

		else if((site%9+1)%3==0)
		{
			cout<<setw(5);
			if(map[site]==0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);//�¦�
				cout<<map[site];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}//end else
			else if(map[site]!=Board[site])
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);//���
					cout<<map[site];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				}
				else
					cout<<map[site];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//������j�u
			cout<<"�x";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}//end else if

		else if(site%3==0 && site%9!=0)
		{
			cout<<"  ";
			if(map[site]==0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);//�¦�
				cout<<map[site];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}//end else
			else if(map[site]!=Board[site])
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);//���
					cout<<map[site];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				}
				else
					cout<<map[site];
		}//end else if
		else
		{
			cout<<setw(5);
			if(map[site]==0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);//�¦�
				cout<<map[site];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}//end else
			else if(map[site]!=Board[site])
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);//���
					cout<<map[site];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				}
				else
					cout<<map[site];
		}//end else
	}//end for
}//end Sudoku::show()



int Sudoku::SolveSudoku(int *b)
{
  int p, num, r, c, l, s, i, a=0;
  for(p=M_MAX-1; p>=0 && b[p]!=0; p--);   // ��M�Ů� 
  if (p>=0)
  {  // p���Ů��m 
    r=p/M_SIZE; c=p%M_SIZE;  l=r/m_row*m_row*M_SIZE+c/m_col*m_col;  // ��m���� 
    for(num=1; num<=M_SIZE; num++)   // �N��J���Ʀr 
    { 
      b[p] = num;       
      for(i=0; i<M_SIZE; i++)  // �ˬd ��C�P�p�E�c���O�_���� 
      {
        s = l + i/m_col*M_SIZE+i%m_col;
        if((i!=c && b[r*M_SIZE+i]==num) || ( i!=r && b[i*M_SIZE+c]==num)
           || ( s!=p && b[s]==num) )  break;  //�����Ыh���� 
      }
      if (i==M_SIZE && SolveSudoku(b)!=0) a=1;  //�S���Ыh�~��...[���j] 
      if (m_ans>1) break;  // ���h���� -- 
    }
    b[p] = 0;
    return a;
  }
  if (m_ans++<1)
    for(p=0; p<M_MAX; p++) Solve[p] = b[p];   // �O���ѵ� 
  return 1;  
}

int Sudoku::DigSudoku()
{
   int d, ka, kb, kc; 
   int Dig[(M_SIZE*M_SIZE+1)/2];   // ���}����
   for(d=0; d<m_mid; d++) Dig[d]=d;
   for(d=0; d<m_mid; d++)  // ���ë��}����
   {
      int n = rand()%m_mid;
      int t = Dig[n];  Dig[n]=Dig[d]; Dig[d] = t;  //�洫     
   }     
   for(d=0; d<m_mid; d++)
   {
      m_ans=0; kb = -1; kc = M_MAX-Dig[d]-1;
      ka = Board[Dig[d]];  Board[Dig[d]]=0;  // ���}
      if (kc!=Dig[d]) 
      {  kb = Board[kc];  Board[kc] = 0; }   // ��٫��}
      SolveSudoku(Board);
      if (m_ans>1)  // ���h����, ���}�ݶ�^
      {
         Board[Dig[d]] = ka;
         if (kb>0) Board[kc] = kb;
      }
   }
   for(int i=0; i<M_MAX; i++) Solve[i]=0;
   return 1;
}

void Sudoku::equivalent()
{
	int site;
	for(site=0;site<M_MAX;site++)
	{
		Play[site]=Board[site];
		Solve[site]=Board[site];
	}
}
 
/*
int main()
{
	srand(time(NULL));

	Sudoku player;	

	cout<<"�w��Ӫ��ƿW~"<<endl;
	cout<<"�ޥΦ�: http://homepage.seed.net.tw/web/ading\n"<<endl;
	system("PAUSE");

	while(!player.play())
	{}


	system("PAUSE");
	return 0;
}

*/