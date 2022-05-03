#include <stdlib.h>
#include <string.h>

/* Необходимые файлы ядра */
#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"
unsigned int PORTF;
/*-----------------------------------------------------------*/
/* Функция задачи 1 */
void vTask1( void *pvParameters )
{
    /* Как и большинство задач, эта задача содержит
/* бесконечный цикл */
    for( ;; )
    {
        /* Инвертировать бит 0 порта PORTF */
        PORTF ^= (1 << 1);
        /* Задержка на некоторый период Т1*/
        for( unsigned long ul = 0; ul < 4000L; ul++ )
        {
            /* Это очень примитивная реализация задержки,
             /* в дальнейших примерах будут использоваться
             /* API-функции */
        }
    }
    /* Уничтожить задачу, если произошел выход
/* из бесконечного цикла (в данной реализации выход
/* заведомо не произойдет) */
    vTaskDelete( NULL );
}
/*-----------------------------------------------------------*/
/* Функция задачи 2, подобная задаче 1 */
void vTask2( void *pvParameters )
{
    volatile unsigned long ul;
    for( ;; )
    {
        /* Инвертировать бит 1 порта PORTF */
        PORTF ^= (1 << 2);
        /* Задержка на некоторый период Т2*/
        for( ul = 0; ul < 8000L; ul++ )
        {
        }

    }
    vTaskDelete( NULL );
}
/*-----------------------------------------------------------*/


short main( void )
{
    PORTF = 0;
    /* Создать задачу 1, заметьте, что реальная программа должна
/* проверять возвращаемое значение, чтобы убедиться,
/* что задача создана успешно */
    xTaskCreate(vTask1, /* Указатель на функцию,

            /* реализующую задачу */
                (signed char *) "Task1", /* Текстовое имя задачи.

            /* Только для наглядности */
                configMINIMAL_STACK_SIZE, /* Размер стека –

            /* минимально необходимый*/
                NULL,
                /* Параметр, передаваемый задаче, –

            /* не используется */
                1,
                /* Приоритет = 1 */
                NULL ); /* Получение дескриптора задачи – не используется */

    /* Создать задачу 2 */
    xTaskCreate( vTask2 , ( signed char * ) "Task2",
                           configMINIMAL_STACK_SIZE, NULL, 1, NULL );
    /* Запустить планировщик. Задачи начнут выполняться. */
    vTaskStartScheduler();
    return 0;
}
/*-----------------------------------------------------------*/
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
