# My_Basket c++ project

## Содержание 

1. [Содержание](#содержание)
1. [Описание проекта](#описание-проекта)
1. [Реализация](#реализация)
   * [Классы и объекты](#классы-и-объекты)
    * [Алгоритмы](#алгоритмы)
    
1. [Пользовательские сценарии](#пользовательские-сценарии)
1. [Функции доступные пользователю](#функции-доступные-пользователю)
1. [Приложения-аналоги](#аналоги-приложения)


## Описание проекта
Пользователь выбирает несколько продуктов, складывая их в "свою корзину".
Программа выдает список из нескольких рецептов, которые возможно приготовить из 
набранной корзины. Также есть возможность, наоборот, по названию блюда получить 
состав и инструкцию по приготовлению. В выпадающем окне предлагается выбрать категорию магазина. 
Рассчитывается стоимость общей покупки, анализируется, в каком магазине заданной категории совершить 
покупку выгоднее всего - пользователь получает название сетевого магазина + цену покупки + адреса 
магазинов этой сети в городе. Программа локализована под город Санкт-Петербург.

## Реализация
   ### Классы и объекты
- поисковая строка search продуктов
- поисковая строка search рецептов
- в начале работы с приложением кнопка "выберите ваш город" (опционально)
- главный экран приложения - с кликабельными картинками продуктов и рецептов
- два типа галочек (желательные и нежелательные продукты)
- после выбора продуктов подсвечиваются кнопки "выбрать категорию магазина"  и "подобрать рецепт"
- связь после кнопки ✅ - положить продукт в объект "корзина"
- меню "категории продуктов" и "категории рецептов"
- меню избранных ингредиентов и рецептов
- сама корзина ( структура с полем std::vector, в который пушбекаем рецепты)
- кнопки ✅ - запускают поиск
- кнопка ⛔️ - удаление продукта из корзины
- меню таблица весов и мер
- в описании рецепта -список ингредиентов с весами и объёмами
- а также в описании рецепта может быть кликабельное поле "пошаговая инструкция"
- а ещё  поле "рейтинг рецепта"
- вес и объём ингредиентов - объекты, при нажатии на которых показывается альтернативная единица измерения
- напротив каждого рецепта кнопка "подобрать категорию магазина"
- раздел категории магазинов: premium, not-premium. Две кликабельные картинки
- После клика по категории высвечивается список магазинов отсортированный сверху вниз по возрастанию цены продуктов выбранного рецепта
- кнопка "конкретно по вашему набору не нашлось ни одного рецепта, включающего бы все продукты, но вот наиболее подходящие" (== пример: есть все, кроме фундука :)
- кнопка начать готовку, запускается таймер (опционально)

### Алгоритмы

- алгоритм нахождения по заданному пользователем набору продуктов (= корзине) выдавать список рецептов
    - от вариантов с наибольшим включением нужных продуктов к наименьшим
    - подсвечивать разными цветами продукты пользователя и продукты, которые нужно докупить
- алгоритм поиска по названию уже готового блюда рецепта
- алгоритм нахождения по заданному набору продуктов (все продукты уже из полноценного выбранного пользователем рецепта)
- алгоритм поиска минимума стоимости среди магазинов данной категории
- алгоритм подбора рецептов по маске (шаблону)



## Пользовательские сценарии

1. Выбрать продукты в корзинку: добавление продукта либо через графу поиск, либо через картинки на главном экране
1. По набору продуктов получить список подходящих рецептов
1. По блюду получить список подходящих рецептов
1. Выбрать категорию магазина, в котором желаете совершать покупку
1. По набору продуктов получить минимальную стоимость всей корзины + магазин, где это можно купить

## Функции доступные пользователю
1. тыкнуть по изображению продукта, положив её в корзину. При этом на изображении ставится галочка, обозначающая, что вкусняшка выбрана
2. зайти в корзину (в базовой реализации это просто выпадающий список продуктов, но можно и по красоте картинки добавить)
3. выполнить поиск продуктов
4. выбрать категорию магазина
5. выбрать наиболее выгодный магазин данной категории для покупки продуктов
6. выбрать город (опционально)
7. получить адрес магазина по близости к местоположению (опционально)
8. удалить продукт из корзины (снять галочку/ можно добавить значок ⛔️)
9. выбрать категорию продуктов (грибы, макароны, etc)
10. сохранить рецепт в избранное
11.  сохранить ингредиент в избранное
12. узнать рейтинг рецепта (опционально)
13. подобрать рецепты по выбранным продуктам или шаблонам (маске) продуктов
14. при нажатии по картинке рецепта открывается список продуктов с весами и объёмами ( грибы, 150 мг)

    в базовом варианте стоит сделать пока рецепты без картинок, а потом к ним прикручивать что-то

15. при нажатии на вес или объем можно узнать о необходимом количестве продукта в другой единице измерения ( например: доступен вес, хочу узнать сколько чайных ложек)
16. выбрать продукты, которые ни в коем случае не должны быть в рецептах ( другой тип галочек)
17. узнать время готовки рецепта, способ приготовления (опционально)
18. запуск таймера (чтобы понять, например, сколько уже варятся макароны. Возможно за это будет отвечать кнопка "начать готовку" )
19. выбрать категорию рецепта
20. выбрать рецепт, тыкнув по картинке
21. осуществить поиск по рецептам
22. Пошаговое описание рецепта (также опционально, но если сделаем, то круто)

## Аналоги приложения
 * [Recipe book](https://play.google.com/store/apps/details?id=com.desertstorm.recipebook&hl=ru&gl=US) ориентирован на поиск рейтинговых рецептов, способ их приготовления. Продукты можно фотографировать, потом потрясти телефон 
* [Что готовим?](https://play.google.com/store/apps/details?id=ru.gamespace.myfridge&hl=ru&gl=US) совмещает в себе функционал поиска рецептов по продуктам и обратно. Можно выбирать категорию рецептов, сохранять их в избранное, работать с приложением как с поваренной книгой
* [Подбери рецепт](https://play.google.com/store/apps/details?id=com.ggl.jr.cookbooksearchbyingredients&hl=ru&gl=US) Почти такой же функционал, как и в "Что готовим?" + таблица мер и весов
* [Tiendeo](https://www.tiendeo.ru/sankt-peterburg) помогает пользователю найти наиболее выгодный магазин для покупки продуктов
<br/>
  Мы же намерены объединить функционалы этих прекрасных приложений в одно.

    
