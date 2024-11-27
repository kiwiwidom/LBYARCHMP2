# LBYARCHMP2

## Members
- **Campos, Annika Dominique S.**  
- **Tiu, Lance Wilem**

---

## Objective
Convert a grayscale image from an integer representation to a float representation using a hybrid approach of **C** and **x86-64 assembly**.

---

## Key Components
### **Input**
- Image dimensions (height and width).  
- Integer pixel values.

### **Output**
- Float-based grayscale pixel values.

### **Methodology**
1. **C** handles:
   - Memory allocation.
   - Input, output, and timing.
2. **Assembly** performs the conversion:
   - Using scalar SIMD registers for optimized performance.

---

## Formula
$f = \frac{i}{255.0}$

$f$: Float representation of the pixel.  
$i$: Integer representation of the pixel.  

---

## Assembly Function: `imgCvtGrayInttoFloat`
### **Parameters**
- `height`: Number of rows.  
- `width`: Number of columns.  
- `input`: Pointer to integer pixel values.  
- `output`: Pointer to float pixel values.  

---

## How to Run

> nasm -f win64 mp2.asm

> gcc -c cfile.c -o cfile.obj -m64

> gcc cfile.obj mp2.obj -o cfile.exe -m64

> cfile.exe

---

# **Program Output:**
![image](https://github.com/user-attachments/assets/51947680-cf9f-4b71-9704-083da076948d)

# **Correct Output(given in the canvas):**
![image](https://github.com/user-attachments/assets/8005a38b-9fcb-4743-9681-eb785b9bb5b3)


## Performance Analysis ##

# 10 x 10 Image
![image](https://github.com/user-attachments/assets/24018812-db9b-4f70-9321-d7dd1b8b0f95)

# 100 x 100 Image
![image](https://github.com/user-attachments/assets/ccffcd0b-9a3c-4169-a024-ac457c2ed731)

# 1000 x 1000 Image
![image](https://github.com/user-attachments/assets/270f2199-11ef-4804-a9ab-d283a480de47)

| Image Size | Execution Time (avg of 30 runs) |
|------------|---------------------------------|
| 10x10 | 0.000000000 seconds |
| 100x100 | 0.000033333 seconds |
| 1000x1000 | 0.003400000 seconds |

The program achieves excellent performance for the given task, particularly in its ability to handle large data efficiently. It evaluates its execution time over 30 runs, highlighting its speed and scalability. For small images, such as a 10x10 grid, the execution time is at approximately 0.000000000 seconds. When the image size increases to 100x100 pixels, the time remains minimal at 0.000033333 seconds. The real test comes with a significantly larger image of 1000x1000 pixels, which contains over a million values to process. Despite this, the program completes the task in just 0.0034 seconds. These results showcase the program’s efficiency and its ability to process substantial amounts of data while maintaining consistent performance.

