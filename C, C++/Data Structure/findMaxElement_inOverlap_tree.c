//�ߺ� bst tree���� max key ���� elements ã��! ������!!
//
//Alg findMaxElements()
//input Tree t
//output elemenets of max key
//
//1. v<-root()
//2. while(isInternal(v))
//	v<-T.rightChild(v)
//3. v<-parent(v)
//4. k<-key(v)
//5. L<-empty list
//6. while(k=key(v))
//	L.addLast(element(v))
//	if(isRoot(v))
//		return
//	else
//		v<-parent(v)
//7. return L.elements()
//
//// max elements�� �ɲ� �ٸ� �� ����!!!
//Alg findMinElements()
//input Tree t
//output elemenets of min key
//
//1. v <- root()
//2. while (isInternal(v))
//	v <-leftChild(v)
//3. v <- parent(v)
//4. k <- key(v)
//5. L <- empty list
//6. while (isInternal(k))
//		L.addLast(element(v))
//		v <- treeSearch(rightChild(v), k)
//7. return L.elements()