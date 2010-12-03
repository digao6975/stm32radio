#include <rtthread.h>
#include <rtgui/rtgui_server.h>
#include <rtgui/rtgui_system.h>
#include <rtgui/widgets/workbench.h>

#include "lcd.h"
#include "key.h"
#include "touch.h"

void gui_init()
{
	extern void workbench_init(void);
    rtgui_rect_t rect;

	/* ��ʼ��RT-Thread/GUI server */
    rtgui_system_server_init();

    /* ע����� */
    rect.x1 = 0;
    rect.y1 = 0;
    rect.x2 = 240;
    rect.y2 = 320;
    rtgui_panel_register("main", &rect);
    rtgui_panel_set_default_focused("main");

	/* ��ʼ��LCD���� */
    rt_hw_lcd_init();

	/* ��ʼ���������� */
	rt_hw_key_init();

	/* ��ʼ������������ */
	rt_hw_touch_init();

	/* ��ʼ��workbench */
	workbench_init();
}
