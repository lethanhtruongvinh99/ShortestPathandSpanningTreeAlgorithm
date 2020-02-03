#include "GRAPH.h"
#include <fstream>

int main()
{
	int** adjList = new int*[MAX_N];
	for (int i = 0; i < MAX_N; i++)
	{
		adjList[i] = new int[MAX_N];
	}
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			adjList[i][j] = 0;
			adjList[i][j] = 0;
		}
	}

	fstream inFile;
	inFile.open("input.txt", ios::in);
	fstream outFile;
	outFile.open("output.txt", ios::out);
	do
	{
		string buffer;
		inFile >> buffer;
		if (buffer == "CREATE")
		{
			int u, v, w;
			inFile >> u >> v >> w;
			outFile << CREATE(u, v, w, adjList) << endl;
			
		}
		else if (buffer == "DELETE")
		{
			int u, v;
			inFile >> u >> v;
			outFile << DELETE(u, v, adjList) << endl;

		}
		else if (buffer == "SP")
		{
			int start, end;

			inFile >> start >> end;
			--start;
			--end; 
			int*trace = new int[MAX_N];

			int SP = dijkstra(adjList, start, end, trace);
			
			if (SP == -1)
				outFile << SP << endl;
			else
			{
				outFile << SP << endl;
				vector<int> path;
				int id = end;
		
				do
				{
					path.push_back((id + 1));
					id = trace[id];
				} while (id != -1);

				for (int i = path.size() - 1; i >= 1; i--)
				{
					outFile << path[i] << "  " <<path[i - 1] << endl;
				}
				delete[]trace;
			}
		}
	} while (!inFile.eof());
	for (int i = 0; i < MAX_N; i++)
		delete[]adjList[i];
	delete[]adjList;

	inFile.close();
	outFile.close();
	cin.get();
	return 0;
}