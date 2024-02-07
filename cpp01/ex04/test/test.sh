REPLACE_EXTENSION=".replace"

EXEC() {
	printf "%s \"%s\" -> \"%s\"" $1 "$2" "$3"
	./Replacer $1 "$2" "$3"
	if [ $? -eq 0 ] ; then
		echo
		REPLACE_FILE=$1$REPLACE_EXTENSION
		cat $REPLACE_FILE
	else
		# echo "Error"
		printf "\e[31m Error \e[m\n"
	fi
	echo
}

for file in ./test/*.txt
do
	EXEC $file "" "" # 何も変更なく.replaceファイルが作成される
	EXEC $file "1" "" # ファイル内の1が削除される
	EXEC $file "" "1" # 空文字を1に変更するため、変更なし
	EXEC $file "1" "2" # 1を2に変更する
	EXEC $file "1" "1" # 1を1に変更するため、変更なし
	EXEC $file "1" "11" # 1を11に変更するため、1があったところが11になる
	EXEC $file "11" "1" # 11を1に変更するため、11の1一つが削除される
	EXEC $file "11" "" # 11を削除する。1が奇数であれば一つの1が残る
	EXEC $file "a" "A" # toupper("a")
	EXEC $file "A" "a" # tolower("A")
	EXEC $file "TEST" "XXXX" # シンプルに文字列を置換する
done
