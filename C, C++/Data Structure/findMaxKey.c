//Alg findMaxKey()
// input Tree T
// output max key k
//
//1. v<- T.root()
//2. while(T.isInternal(v))
//	v<-T.rightChild(v)
//3. return key(T.parent(v))


//Alg findMinKey()
// input Tree T
// output min key k
//
//1. v<- T.root()
//2. while(T.isInternal(v))
//	v<-T.leftChild(v)
//3. return key(T.parent(v))

