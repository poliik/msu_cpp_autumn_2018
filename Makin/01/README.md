# __Homework 01__

## Задание:
Нужно написать программу считающую сколько раз простое число встречается в указанном диапазоне массива.

Массив состоит из упорядоченных по возрастанию целых чисел (int), числа находятся в диапазоне [0, 100000]. На вход программы поступают пары чисел из первого и последнего числа в диапазоне (пар может быть несколько). Нужно найти в массиве эти числа и вывести в консоль сколько простых чисел находится между ними включительно.

Пример:

```
3 4 4 5 7 8 8 9 11 11 15

./test 4 15
4
```
```
2 2 2 3 3

./test 2 3
5
```

Если заданного числа в массиве нет, то вывести в консоль 0.

Пример:

```
3 4 4 5 7 8 8 9 11 11 15

./test 6 15
0
```

Если ввод некорректен или произошла внутренняя ошибка, вернуть return -1, иначе программа должна возвращать return 0.

> Стандартные алгоритмы использовать нельзя.

## Результат:

```
./test 12 18
ok
./test 1 99999
ok
./test 25 25
ok
./test 30 29
ok
./test 99999 1
ok
./test 97 62285
ok
./test 41753 91449
ok
./test 3 99993
ok
./test 3
ok
./test
ok
./test 3 3 3
ok
./test 12 18 1 99999
ok
bencmarking
0.00630497932434 sec
```
