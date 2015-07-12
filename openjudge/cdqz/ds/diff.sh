export CXX="clang++"
export CXXFLAGS="-Wall -Wextra -g3 -DYGHDEBUG"
make 1004
make 1004_b1
for i in {1..100}:
do
	python gen.py>1004.in
	./1004 < 1004.in>1004.out
	./1004_b1<1004.in>1004.ans
	if(diff -Bb 1004.out 1004.ans)
	then
	echo $i AC
	else 
		echo ! $i
		exit
	fi
done
