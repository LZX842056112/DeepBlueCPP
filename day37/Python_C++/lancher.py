import ctypes
import os
import sys

def main():
    possible_paths = [
        "./c++/libPlaneVsMonsters.dll",
    ]

    dll_path = None
    for path in possible_paths:
        abs_path = os.path.abspath(path)
        if os.path.exists(abs_path):
            dll_path = abs_path
            break

    os.chdir(os.path.dirname(os.path.abspath(__file__)))

    try:
        game_lib = ctypes.CDLL(dll_path)
        print(">>> 游戏启动 >>>")
        game_lib.RunGame()
        print("<<< 游戏结束 <<<")

    except OSError as e:
        print(f"\n加载 DLL 失败: {e}")
    except Exception as e:
        print(f"发生未知错误: {e}")

if __name__ == "__main__":
    main()