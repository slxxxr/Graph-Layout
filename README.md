# Описание
**Graph Layout** - программный комплекс поиска мостов, точек сочленения, компонент связности графа и его визуализация.

Программный комплекс был написан в качестве курсовой работы по программированию с использованием платформы Windows Forms. В качестве языка программирования был выбран C++, так как он является более удобным для меня при работе с алгоритмами.
В качестве средств визуализации графа был выбран язык Python из-за его большого количества библиотек для работы с графами и данными, а именно NetworkX, Matplotlib и NumPy.

# Руководство
## Ввод графа
При запуске вас встречает следующее окно:

![window](https://github.com/slxxxr/Graph-Layout/blob/main/Images/main_window.png)

В левой части экрана находится поле для ввода. Граф вводится списком ребер в 1-нумерации. Сначала вводится количество вершин и ребер соответственно, далее начало и конец каждого ребра. Для удобства рядом с поле ввода находится формат ввода с примером. Также присутствует "легкая" проверка на неверные номера вершин. 
После ввода необходимо выбрать что нужно найти в графе, нажать кнопку "Найти" и справа отобразится граф.
## Примеры 
### Поиск мостов
Ребра, являющиеся мостами, отображаются красным цветом.
![bridges](https://github.com/slxxxr/Graph-Layout/blob/main/Images/test_Bridges.png)

### Поиск точек сочленения
Вершины, являющиеся точками сочленения, отображаются красным цветом.
![points](https://github.com/slxxxr/Graph-Layout/blob/main/Images/test_ArticulationPoints.png)

### Поиск компонент связности
Вершины, принадлежащие одной компоненте, отображаются одним цветом.
![components](https://github.com/slxxxr/Graph-Layout/blob/main/Images/test_Components.png)

