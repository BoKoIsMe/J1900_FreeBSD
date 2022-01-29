template <typename T>
void ei(T &a,T &b);
int main(void)
{
	template void ei<int>(int &,int &);
	template void ei<int>(double &,double &);
	double i = 1,j =2;
	int c = 3,d =4;
	ei(i,j);
	ei(c,d);
	return 0;
}

template <typename T>
void ei(T &a,T &b)// ->decltype (a + b)
{
	a = a + b;
}

