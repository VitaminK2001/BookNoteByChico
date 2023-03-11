import os
from torchvision import transforms
transform = transforms.Compose([
    transforms.ToTensor()
])
from utis import keep_image_size_open

class MyDataset(Dateset):
    def __init__(self, path) -> None:
        self.path = path
        self.name = os.listdir(os.path.join(path, 'SegmentationClass'))

    def __len__(self):
        return len(self)
    
    def __getitem__(self, index):
        segment_name=self.name[index]  # 获取目标文件名
        segment_path=os.path.join(self.path, 'SegmentationClass', segment_name) # 获取目标分割文件路径
        image_path=os.path.join(self.path, 'JPEGImages', segment_name.replace('png', 'jpg')) # 获取源文件路径 源文件的格式是png
        segment_image=keep_image_size_open(segment_path) # 将目标分割文件恢复到和源文件一样大
        image=keep_image_size_open(image_path) 
        return transform(image), transform(segment_image)

