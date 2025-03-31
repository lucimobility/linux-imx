// TODO: header stuff.
// Based off of rtc-em3027.c

#include <linux/i2c.h>
#include <linux/rtc.h>
#include <linux/module.h>

#ifdef CONFIG_OF
#include <linux/of.h>
#endif

// Forward declaration.
static struct i2c_driver lucistm32_driver;

static int lucistm32_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
  // TODO
}

static int lucistm32_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
  // TODO
}

static const struct rtc_class_ops lucistm32_rtc_ops = {
  .read_time = lucistm32_rtc_read_time,
  .set_time = lucistm32_rtc_set_time,
};

static int lucistm32_probe(struct i2c_client *client,
                           const struct i2c_device_id *id)
{
  // TODO
}

static const struct i2c_device_id lucistm32_id[] {
  { "lucistm32", 0 },
    {}
};
MODULE_DEVICE_TABLE(i2c, lucistm32_id);

#ifdef CONFIG_OF
static const struct of_device_id lucistm32_of_match[] = {
  { .compatible = "TODO", },
  {}
};
MODULE_DEVICE_TABLE(of, lucistm32_of_match);
#endif

static struct i2d_driver lucistm32_driver = {
  .driver = {
    .name = "rtc-lucistm32",
#ifdef CONFIG_OF
    .of_match_table = of_match_ptr(lucistm32_of_match),
#endif
  },
  .probe = &lucistm32_probe,
  .id_table = lucistm32_id,
};

module_i2c_driver(lucistm32_driver);

MODULE_AUTHOR("Ross Lannen <ross@luci.com>");
MODULE_DESCRIPTION("LUCI STM32 RTC driver");
MODULE_LICENSE("TODO");
