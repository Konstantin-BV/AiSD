#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\kosty\source\repos\Lab1c\ConsoleApplication1\RBtree.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	RBtree tree;
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Root)
		{
			tree.clear();
			string l = "re";
			tree.Insert(NULL, tree.root, l,1);
			Assert::AreEqual(tree.root->color, 'b');
			Assert::AreEqual(tree.root->key, l);
		}
		TEST_METHOD(Color)
		{
			tree.clear();
			string l = "re";
			tree.Insert(NULL, tree.root, l, 1);
			Assert::AreEqual(tree.root->color, 'b');
			tree.Repainting(tree.root);
			Assert::AreEqual(tree.root->color, 'r');
			tree.Repainting(tree.root);
			Assert::AreEqual(tree.root->color, 'b');
		}
		TEST_METHOD(Child)
		{
			tree.clear();
			string l = "re";
			string p = "e";
			tree.Insert(NULL, tree.root, l,1);
			tree.Insert(NULL, tree.root, p,2);
			Assert::AreEqual(tree.root->key, l);
			Assert::AreEqual(tree.root->left->key, p);
			Assert::AreEqual(tree.root->color, 'b');
			Assert::AreEqual(tree.root->left->color, 'r');
		}
		TEST_METHOD(rotate)
		{
			tree.clear();
			string l = "a";
			string pm = "b";
			string k = "c";
			tree.Insert(NULL, tree.root, l,2);
			tree.Insert(NULL, tree.root, pm,1);
			tree.Insert(NULL, tree.root, k,3);

			Assert::AreEqual(tree.root->key, pm);
			Assert::AreEqual(tree.root->left->key, l);
			Assert::AreEqual(tree.root->right->key, k);

		}
		TEST_METHOD(find)
		{
			tree.clear();
			string l = "a";
			string pm = "b";
			string k = "c";
			int i = 1, q = 2, w = 3;
			tree.Insert(NULL, tree.root, l,i);
			tree.Insert(NULL, tree.root, pm,q);
			tree.Insert(NULL, tree.root, k,w);
			Assert::AreEqual(tree.find(pm)->key, pm);
			Assert::AreEqual(tree.find(l)->key, l);
			Assert::AreEqual(tree.find(k)->key, k);

		}
		TEST_METHOD(map)
		{
			tree.clear();
			string l = "a";
			string pm = "b";
			string k = "c";
			int i = 1, q = 2, w = 3;
			tree.Insert(NULL, tree.root, l, i);
			tree.Insert(NULL, tree.root, pm, q);
			tree.Insert(NULL, tree.root, k, w);
			Assert::AreEqual(tree.find(pm)->value, q);
			Assert::AreEqual(tree.find(k)->value, w);
			Assert::AreEqual(tree.find(l)->value, i);

		}

		TEST_METHOD(deleter)
		{
			tree.clear();
			string l = "a";
			string pm = "b";
			string k = "c";
			string a = "d";
			int i = 1, q = 2, w = 3,m=4;
			tree.Insert(NULL, tree.root, l, i);
			tree.Insert(NULL, tree.root, pm, q);
			tree.Insert(NULL, tree.root, k, w);
			tree.Insert(NULL, tree.root, a, m);
			Assert::AreEqual(tree.find(pm)->key, pm);
			Assert::AreEqual(tree.find(l)->key, l);
			Assert::AreEqual(tree.find(k)->key, k);
			Assert::AreEqual(tree.find(a)->key, a);
			Assert::AreEqual(tree.find(a)->color, 'r');
			Assert::AreEqual(tree.root->right->key, k);
			tree.remove(tree.find(k));
			Assert::AreEqual(tree.root->right->key, a);
			Assert::AreEqual(tree.find(a)->color, 'b');
		}
	};
}
