Задание:
--------
Необходимо разработать программу, которая анализирует словарь английских слов и определяет, сколько из них могут быть набраны на QWERTY-клавиатуре с английским языком, передвигаясь только по смежным клавишам. При этом можно нажимать одну и ту же клавишу дважды подряд.

Условия:
 ∙ Входные данные: файл со списком английских слов (одно слово на строку).
 ∙ Раскладка клавиатуры: стандартная английская QWERTY.
 ∙ Клавиши считаются смежными, если они находятся горизонтально или вертикально рядом друг с другом. Диагональное расположение также считается смежным, но только для клавиш, расположенных на одинаковом расстоянии от левого края. Так, 's' и 'w', а также 's' и 'z' считаются смежными, но 's' и 'q' - не считаются смежными.
 ∙ Каждую клавишу можно нажимать дважды подряд.
Задача – посчитать и вывести количество английских слов, которые можно набрать, используя только смежные клавиши на QWERTY-клавиатуре.

------------------------------------------------------------------------------------------------------------------
Пояснение:
----------
Программа собиралась GCC в Linux. При запуске можно указать свой файл-словарь, если не словарь не указан, то используется "dictionary.csv".
Логика программы: клавиатура представлена в виде символьного (буквенные клавиши) 2х-мерного массива 3х10 (kb_array), для наглядности отсутствующие клавиши обозначены в массиве символом '*'.
После считывания слова оно переводится в верхний регистр (ф. UpCase) и символ (если есть) '\n' заменяется на '\0'. Затем слово передается в функцию анализатор CheckWord() где в цикле выполняются следующие шаги: 
1. берется последовательно буква слова и по ней создается массив букв из смежных клавиш (ф. CreateArrayKBchar).
2. Затем во втором цикле ищется вхождение каждой буквы слова в полученном массиве смежных клавиш до 1-го не совпадения (и тогда возвращаемся к шагу 1 и берем следующую букву из слова), если же все буквы входят в массив, то слово найдено и возвращаем соответствующий флаг в осной цикл чтения слов из файла, где все повторяем пока не дойдем до конца файла.

