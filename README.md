# drupal_7
Currency exchange rate module for Drupal 7

Модуль добавляет пункт меню Курсы валют по пути "/all_days_rates". На данной странице отображается таблица с курсами валют. В шапке
таблицы сформированы ссылки страницы с графиком курса валюты за период и загрузкой данных в виде нод.
Ссылка на получение JSON массива курсов за период формируется после построения графика.

Установка:
Устанавливается как обычный модуль Drupal 7.
Потребуется установка библиотеки highcharts.js для построения графиков.

Настройка:
Сам модуль не имеет настроек.
В дефолтных настройках модуля charts необходимо поставить библиотеку по-умолчанию highcharts.js.

Зависимости:
 - views
 - visualization
 - charts
 - date
 - highcharts
 
