#include <iostream>;
using namespace std;

struct node {
	char value;
	node* left;
	node* right;
};

class BinarySearchTree {
public:
	node* root = NULL;
	bool find = false;
	void separate(string pre, string in, node*& side) {
		string leftNode, rightNode, leftRoot, rightRoot;
		char rootC = pre[0];
		build(side, rootC);
		while (in[0] != rootC) {
			leftNode += in[0];
			in.erase(0, 1);
		}
		in.erase(0, 1);
		rightNode = in;
		pre.erase(0, 1);
		for (int i = 0; i < pre.length(); i++) {
			bool find = false;
			for (int j = 0; j < leftNode.length(); j++) {
				if (pre[i] == leftNode[j]) {
					leftRoot += pre[i];
					find = true;
					break;
				}
				if (!find && j == leftNode.length() - 1)rightRoot += pre[i];
			}
		}
		if (leftRoot.length() > 0)separate(leftRoot, leftNode, side->left);
		else {
			while (leftNode.length() > 0) {
				build(side->left, leftNode[leftNode.length()-1]);
				leftNode.pop_back();
			}
		}
		if (rightRoot.length() > 0)separate(rightRoot, rightNode, side->right);
		else {
			while (rightNode.length() > 0) {
				//cout << rightNode << ' '<< rightNode[rightNode.length() - 1]<<' '<<endl;
				node* tmp = side->right;
				build(tmp, rightNode[rightNode.length() - 1]);
				
				rightNode.pop_back();
			}
		}
	}

	void build(node*& root, char insert) {
		node* add;
		add = new node;
		add->value = insert;
		add->left = NULL;
		add->right = NULL;
		root = add;
	}

	void postOrder() {
		postOrder(root);
	}


private:
	void postOrder(node* tree) {
		if (tree->left)postOrder(tree->left);
		if (tree->right)postOrder(tree->right);
		cout << tree->value;
	}
};


int main() {
	BinarySearchTree tree;
	string pre, in;
	while (cin >> pre >> in) {
		tree.root = NULL;
		tree.separate(pre, in, tree.root);
		tree.postOrder();
		cout << endl;
	}
}