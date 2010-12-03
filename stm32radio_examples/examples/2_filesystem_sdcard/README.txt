����һ���ļ�ϵͳʹ��SD��������

SD��������sdcard.c/.h��ʵ�֣�Ҫʵ��һ�����豸���͵���������Ҫʵ����Ӧ������ӿڣ�
static rt_err_t rt_sdcard_init(rt_device_t dev);
static rt_err_t rt_sdcard_open(rt_device_t dev, rt_uint16_t oflag);
static rt_err_t rt_sdcard_close(rt_device_t dev);
static rt_size_t rt_sdcard_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size);
static rt_size_t rt_sdcard_write (rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size);
static rt_err_t rt_sdcard_control(rt_device_t dev, rt_uint8_t cmd, void *args);

��һ���µĿ��豸������ʵ��ʱ��RT-Thread/Device Filesystem�Ϳ���������ʹ���Լ����ļ�ϵͳ�ˣ�
�����ù��ĵײ���ʲô����Ӳ��(�����SPI flash��Ҳ�ܹ��������ֳ���)��

�ļ�ϵͳ
--------
�ļ�ϵͳ��application.c�ĳ�ʼ���߳��н���װ�أ�
/* thread phase init */
void rt_init_thread_entry(void *parameter)
{
    /* Filesystem Initialization */
#ifdef RT_USING_DFS
    {
        /* init the device filesystem */
        dfs_init();

        /* init the elm FAT filesystam*/
        elm_init();

        /* mount sd card fat partition 1 as root directory */
        if (dfs_mount("sd0", "/", "elm", 0, 0) == 0)
            rt_kprintf("File System initialized!\n");
        else
            rt_kprintf("File System init failed!\n");
    }
#endif
}

dfs_init()��elm_init()�ֱ���device filesystem��elm fatfs�ļ�ϵͳ�ĳ�ʼ���������ǳ�ʼ����Ϻ�Ϳ���װ���ļ�ϵͳ��
dfs_mount("sd0", "/", "elm", 0, 0)

��һ���������豸��������elm fatfs�ļ�ϵͳ���ԣ�����豸һ��Ҫ���ڷ����ܹ�װ�سɹ���
�ڶ���������װ�ص�Ŀ¼�������Ǹ�Ŀ¼�����Ҫװ�ص���ͬ��Ŀ¼����ô����Ҫȷ�����Ŀ¼�����ڵ��ļ�ϵͳ���Ѿ����ڡ�
�������������ɺ��Բ��ơ�

-----------
��򵥵Ĳ��Է���:
finsh>>ls("/")
�����ļ�ϵͳ�����������finsh������ list()
