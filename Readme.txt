
================================================
			READ ME - ARKAVQUARIUM
================================================

classes:

	1. Object
		class abstract yang merupakan parent class dari semua class lain, memiliki method draw, move untuk mengakomodasi GUI tugas kedepannya. (semua object akan digambar, tapi tidak semua bergerak)

	2. Aquarium 
		inherit object
		class aquarium berupa container / controller dari kelas kelas lain. (memiliki list of fish dan object object lainnya)
		class aquarium juga mengatur penciptaan dan pemusnahan object lain dalam aquarium

	3.  LinkedList
		class yang berupa class generic, berupa array / vector untuk menampung berbagai object dengan jenis yang sama
		digunakan dalam aquarium, sebagai container object
	
	4.	Coin 
		inherit object
		salah satu object dalam game, merepresentasikan coin yang di drop oleh ikan

	5.	Food
		inherit object
		Salah satu object dalam game, merepresentasikan makanan yang di munculkan dalam aquarium

	6. 	Fish
		inherit object
		class yang merupakan parent class dari semua class ikan ikan lainnya. 

	7.	Guppy 
		inherit Fish
		memiliki atribut growth level yang berbeda dengan ikan lainnya
		merepresentasikan ikan kuning / standar dalam game

	8.	Piranha
		inherit Fish
		merepresentasikan ikan piranha dalam game

	9.	Pet 
		inherit object 
		merupakan parent class dari semua pet (karakter non ikan yang berfungsi membantu player dalam game)
		class dibuat untuk mengakomodasi apabila perlu dikembangkan pet yang lain

	10.	Siput
		inherit Pet
		merepresentasikan salah satu jenis pet yaitu snail (siput)