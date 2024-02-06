EXEC() {
	echo "[" $1 "]"
	printf "*** $(head -n 1 $1) ***\n"
	./phonebook < $1
	echo
}

for file in ./test/*.txt
do
	EXEC $file
done
