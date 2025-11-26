from PIL import Image

original_image="CR.jpg"
img = Image.open(original_image)

mirror_img=img.transpose(Image.FLIP_LEFT_RIGHT)
mirrored_image="CR_mirrir.jpg"
mirror_img.save(mirrored_image)
Image.open(mirrored_image)
