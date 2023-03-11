from PIL import Image

def keep_image_size_open(path, size=(256,256)) -> Image:
    img = Image.open(path)  # 获得原图片的路径
    temp = max(img.size)  # 获得原图片的大小
    mask = Image.new('RGB', (temp, temp), (0, 0, 0))  # 生成灰度图
    mask = mask.paste(img, (0, 0))
    mask = mask.resize(size)
    return mask

