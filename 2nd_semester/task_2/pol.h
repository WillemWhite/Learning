﻿/*
чтобы не было вопросов к моему пониманию следующих действий:
первая директива проверяет, был ли ранее использован макрос-объект 
POL_H, далее мы добавляем этот макрос-объект. Делаю это с той целью, 
чтобы мой заголовочный файл не добавлялся несколько раз в одну и ту же 
программу. Если добавится 2 и более раз, то остальные заголовочные файлы 
будут пустыми благодаря данной конструкции. Сейчас это полезно больше в 
плане привычки, нежели реально играет роль в работе программы.
*/

#ifndef POL_H
#define POL_H

void inpConditions(int, float);

void testPolComputation();

float polComputation(int, float);

#endif
