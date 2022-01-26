#include <iostream>
#include <string>
using namespace std;
template <typename T>
const T &cmpBox(const T &a,const T &b);
struct box
{
	string maker;
	double height;
	double width;
	double length;
	double volume;
};
//显式具体化 box
template <> const box & cmpBox<box>(const box &a,const box &b);// -> decltype(box);
box & setBoxVolume(box & currtBoxVolume);
void showBoxMember(const box & crtBox);
int main(void)
{
	//box box1 = {"blue",15,20,30,};
	box box2 = {"red",18.8f,21.6f,14.2f,};
	box box3 = {"green",13.333f,22.222f,19.456f,};
	//showBoxMember(v1 = setBoxVolume(box1));
	showBoxMember(setBoxVolume(box2));
	showBoxMember(setBoxVolume(box3));
	//cmpBox(box2.volume,box3.volume);
	//cmpBox(&box2,&box3);
	cout << cmpBox(box2.volume,box3.volume) << ":" << cmpBox(box2,box3).maker << endl;
	return 0;
}
box & setBoxVolume(box & currtBoxVolume)
{
	currtBoxVolume.volume = currtBoxVolume.height * currtBoxVolume.width * currtBoxVolume.length;
	return currtBoxVolume;
}
void showBoxMember(const box & crtBox)
{
	cout << "box maker: " << crtBox.maker << "\n";
	cout << "height = " << crtBox.height << "mm\n";
	cout << "width= " << crtBox.width << "mm\n";
	cout << "length = " << crtBox.length << "mm\n";
	cout << "volume = " << crtBox.volume / 1000 << "L\n" << endl;
}
template <typename T>
const T &cmpBox(const T &a,const T &b)
{
	return (a > b)?a:b;
}
//具体化实现
template <> const box & cmpBox<box>(const box &a,const box &b)
{
	return (a.volume > b.volume)?a:b;
}

