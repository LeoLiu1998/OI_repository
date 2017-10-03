export CXX="clang++"
export CXXFLAGS="-Wall -Wextra -g3 -DYGHDEBUG"
name=kingh
bname=king2
gen_name=gen
make $name 
make $bname
for i in {1..1000}:
do
	./$gen_name>$name.in
	./$name < $name.in>$name.out
	./$bname<$name.in>$name.ans
	if (diff -q -Bb  $name.out $name.ans)
	then
	echo $i AC
	else 
		echo ! $i
		exit
	fi
done
