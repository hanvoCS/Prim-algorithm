#include <cstdlib>
#include<iostream>
#include<vector> 

using namespace std;

void prim(vector<vector<int> >graph, int N) {


	vector<int>  visited;
	
	int min, src, des, MST = 0, i, j;

	for (i = 0; i < N; i++)
	{
		visited.push_back(0); // nodes are not visited yet 
	}

	cout << "enter the source for finding the minimum spanning tree :";
	cin >> src;
	visited[src] = 1;

	int path = 0;

	cout << endl << " the  minimum spanning tree path :" << endl;
	

	while (path < N - 1) {
		min = 9999;

		for (i = 0; i < N; i++)
		{
			if (visited[i] == 1)
			{
				for (j = 0; j < N; j++)
				{
					if (visited[j] == 0)
					{
						if (min > graph[i][j])
						{
							min = graph[i][j];
							src = i;
							des = j;

						}
					}
				}

			}
		}
		if (graph[src][des] != 9999) {
			visited[des] = 1;
			MST = MST + graph[src][des];  // cost of MST
			cout << src << "-------->" << des << " with cost :" << min << endl;
		}
		
			path++;
		} cout << endl << "cost of MST is :" << MST << endl;
}



void start(vector<vector<int> >graph, int N, int E) {

	int cost, src, des;
cout << "\n enter source --------cost-------->destination : " << endl;
	cout << "from : 0  t0 :" << N - 1 << endl;
	int A = N + 1;
	for (int i = 0; i < E; i++) {
		cout << i+1<< ": ";
		bool flag = 1;	
		while (flag) {	
			//cin >> src;

		src= rand() % A ;
		cout << src;
			if (src > N - 1 )
			 	cout << "invalid source try again \n";
			else flag = 0;
		}
		cout << "--------";
		flag = 1; 
		while (flag) {
			cost = rand() % 30 + 1;
			if (cost < 0) {
				cout << "invalid cost number ";
			}
			else flag = 0;
		}
		cout << cost;
		cout << "-------->";
		flag = 1; 
		while (flag) {
			// cin>>des;
			 des = rand() % N;
			 cout << des;
			if ((des > N - 1))
				cout << "invalid  destination try again \n";
			else flag = 0;
		}
		cout << endl;
		graph[src][des] = cost;
		graph[des][src] = cost;
	}


	// display all element 
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[i].size(); j++) {

			cout <<"\t"<< graph[i][j];
		}
		cout << endl << "---------------------------------------------------------------------------------------------" << endl;
	}

	prim(graph, N); // call prim function which gives MST
}




int main() {

	 int N, E;
	bool flag = 1;
	
	//while (flag) {
		
		cout << "please enter number of vertices: ";
		cin >> N;
//		if (N < 50) {
		//	cout << " must be greater than  or equal 50 verteces  \n";
		//}
	//	else  flag = 0;
	
		
	//}
//	flag = 1; 
	while (flag) {
		cout << "please enter number of Edges: ";
		cin >> E;

		 if (E < (N-1)) {

			 cout << "error : unconnected Graph ... Try again \n "; 
		}
		else flag = 0; 
	}
	
	vector<vector<int> >graph;


	for (int i = 0; i < N; i++) {
		vector<int> row; // Create an empty row
		for (int j = 0; j < N; j++) {
			row.push_back(9999);  // insilize all row by 999 which represent infinite number 
		}
		graph.push_back(row); // Add the row to the main vector
	}
	
	
	start(graph, N, E); // start creating graph 

	

	system("pause");
	return 0;
}

