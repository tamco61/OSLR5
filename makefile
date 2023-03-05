all:
	# Опция -fPIC - требует от компилятора, при создании объектных файлов,
    # порождать позиционно-независимый код (PIC - Position Independent Code),
    # его основное отличие в способе представления адресов. Вместо указания фиксированных
    # (статических) позиций, все адреса вычисляются исходя из смещений заданных в глобальной
    # таблицы смещений (global offset table - GOT). Формат позиционно-независимого кода позволяет
    # подключать исполняемые модули к коду основной программы в момент её загрузки. Соответственно, основное
    # назначение позиционно-независимого кода - создание динамических (разделяемых) библиотек.
	g++ -fPIC -c lib1.cpp -o d1.o 
	g++ -fPIC -c lib2.cpp -o d2.o
	# Опция -shared - указывает gcc, что в результате должен быть собран не исполняемый файл,
	# а разделяемый объект - динамическая библиотека.
	g++ -shared -o libd1.so d1.o -lm
	g++ -shared -o libd2.so d2.o -lm
	# Oпция -Wl,-rpath,. - уже знакомая конструкция, передать линковщику опцию -rpath с аргументом ..
	# С помощью -rpath в исполняемый файл программы можно прописать дополнительные пути по которым
	# загрузчик разделяемых библиотек будет производить поиск библиотечных файлов.
	# В нашем случае прописан путь . - поиск файлов библиотек будет начинаться с текущего каталога.
	g++ main2.cpp -L. -ldl -o main2.out -Wl,-rpath -Wl,.
	g++ main1.cpp -L. -ld1 -o main1.out -Wl,-rpath -Wl,..