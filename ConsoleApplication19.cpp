// ConsoleApplication19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>
#include <limits> 
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;
class Figures
{
public:
	float x;
	float y;
	float z;

	Figures()
	{

	}

	virtual ~Figures()
	{}
};
class Circle : public Figures
{
public:
	Circle()
	{}


	virtual~Circle()
	{}
};
class Point : public Figures
{
public:
	Point()
	{

	}
	virtual~Point()
	{}
};
class Polyline : public Figures
{
public:
	Polyline()
	{}
	virtual ~Polyline()
	{}
};
class Vertex : public Figures
{
public:
	Vertex()
	{}

};

class Ellipse : public Figures
{
public:
	Ellipse()
	{}

};
string remove_spaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

auto detect_obj(string obj, string &line, ofstream &file){
	while (remove_spaces(line) != obj)
		getline(file, line);

	if (remove_spaces(line) == "10")
	{

		string::size_type sz;
		getline(file, line);

		float a = stof(line, &sz);

		circl->x = a;
		getline(file, line);

		if (remove_spaces(line) == "20")
		{
			getline(file, line);

			float b = stof(line, &sz);
			circl->y = b;
			getline(file, line);

			if (remove_spaces(line) == "30")
			{
				getline(file, line);

				float c = stof(line, &sz);
				circl->z = c;
			}
		}

}


int main()
{
	setlocale(LC_ALL, "ru");
	vector<Figures*>V;
	V.push_back(new Figures);
	string line;
	const char* path = "model.dxf";
	fstream file;
	file.open(path);


	if (file.is_open())
	{
		while (!file.eof())
		{

			getline(file, line);
			Circle* circl = new Circle;
			Point* point = new Point;
			string word;
			map <string, int> result;
			while (file >> word)
				if (std::accumulate(word.begin(), word.end(), 0, [](int value, const char& elem)->int
					{
						return (isalpha(elem)) ? ++value : value;
					}) == word.size())
					if (result.find(word) == result.end())result[word] = 1;
					else result[word]++;
					auto iter = result.begin();
					for (int i = 0; i < result.size(); i++, iter++) 
					{
						if (i % 20 == 0 && i != 0)cout << endl;
						cout << iter->first << " " << iter->second << " ";
					};
			if (remove_spaces(line) == "CIRCLE")
			{

				detect_obj("CIRCLE", line, file);

				}
				V.push_back(circl);
				cout << "CIRCLE" << endl;
				cout << "x[0]:" << " " << circl->x << endl;
				cout << "y[0]:" << " " << circl->y << endl;
				cout << "z[0]:" << " " << circl->z << endl;

			}


			/*getline(file, al);
			if (remove_spaces(al) == "POINT")
			{

				while (remove_spaces(al) != "10")
					getline(file, al);

				if (remove_spaces(al) == "10")
				{

					string::size_type sz;
					getline(file, al);
					float a = stof(al, &sz);
					point->x = a;
					getline(file, al);
					if (remove_spaces(al) == "20")
					{
						getline(file, al);

						float b = stof(al, &sz);
						point->y = b;
						getline(file, al);

						if (remove_spaces(al) == "30")
						{
							getline(file, al);

							float c = stof(al, &sz);
							point->z = c;
						}
					}

				}



				V.push_back(point);
				cout << "POINT" << endl;
				cout << "x[0]:" << " " << point->x << endl;
				cout << "y[0]:" << " " << point->y << endl;
				cout << "z[0]:" << " " << point->z << endl;
			}*/

		}

	}

	return 0;
}
