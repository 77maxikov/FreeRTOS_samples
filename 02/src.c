#include <stdlib.h>
#include <string.h>

/* Необходимые файлы ядра */
#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"

/* Структура, содержащая передаваемую в задачу информацию */
typedef struct TaskParam_t {
    char name[32]; /* строка */
    long period;		 /* период */
} TaskParam;
/* Объявление двух структур TaskParam */
TaskParam xTP1, xTP2;
/*-----------------------------------------------------------*/
/* Функция, реализующая задачу */
void vTask( void *pvParameters )
{
    volatile long ul;
    volatile TaskParam *pxTaskParam;
    /* Преобразование типа void* к типу TaskParam* */
    pxTaskParam = (TaskParam *) pvParameters;

    for( ;; ){
        /* Вывести на экран строку, переданную в качестве параметра при создании задачи */
        puts( (const char*)pxTaskParam->name );

        /* Задержка на некоторый период Т2*/
        for( ul = 0; ul < pxTaskParam->period; ul++ )
        {
        }
    }
    vTaskDelete( NULL );
}

/*-----------------------------------------------------------*/
/* Точка входа. С функции main() начнется выполнение программы. */
short main( void ){
    /* Заполнение полей структуры, передаваемой Задаче 1 */
    strcpy(xTP1.name, "Task 1 is running");
    xTP1.period = 10000000L;
    /* Заполнение полей структуры, передаваемой Задаче 2 */
    strcpy(xTP2.name, "Task 2 is running");
    xTP2.period = 30000000L;
    /* Создание Задачи 1. Передача ей в качестве параметра указателя на структуру xTP1 */
    xTaskCreate( vTask, /* Функция, реализующая задачу */
                 ( signed char * ) "Task1",
                 configMINIMAL_STACK_SIZE,
                 (void*)&xTP1, /* Передача параметра */
                 1, /* Приоритет */
                 NULL );
    /* Создание Задачи 2. Передача ей указателя на структуру xTP2 */
    xTaskCreate( vTask,
                 ( signed char * ) "Task2",
                 configMINIMAL_STACK_SIZE,
                 (void*)&xTP2,
                 1,
                 NULL );
    /* Запуск планировщика */
    vTaskStartScheduler();
    return 1;
}/*-----------------------------------------------------------*/
void vAssertCalled( const char * const pcFileName,
                    unsigned long ulLine ){

}
void vApplicationDaemonTaskStartupHook( void )
{
    /* This function will be called once only, when the daemon task starts to
     * execute    (sometimes called the timer task).  This is useful if the
     * application includes initialisation code that would benefit from executing
     * after the scheduler has been started. */
}
