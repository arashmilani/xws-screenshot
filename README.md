# xws-screenshot

A simple program written in C to take screenshots using `X Windows System` API. 
The PNG output is not optimal; it is 20-50% larger than the file written by a decent optimizing implementation. The `stb_image_write` function is designed for source code compactness and simplicitly, not optimal image file size or run-time performance.
