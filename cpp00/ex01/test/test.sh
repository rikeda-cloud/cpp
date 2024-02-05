EXEC() {
	printf "*** $(head -n 1 $1) ***\n"
	./phonebook < $1
}

for file in ./test/*.txt
do
	EXEC $file
done
