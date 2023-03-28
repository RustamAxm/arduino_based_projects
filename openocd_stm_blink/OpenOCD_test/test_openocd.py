from openocd import OpenOcd
import time

with OpenOcd() as oocd:
    # oocd.halt()
    oocd.resume()

    start = time.time()
    max_i = 2000
    for i in range(100, max_i, 100):
        registers = oocd.read_registers(['pc', 'sp'])

        memory = oocd.read_memory(0x0000000020000484, 2, 32)
        print([hex(x) for x in memory])
        print('Program counter: 0x%x' % registers['pc'])
        print('Stack pointer: 0x%x' % registers['sp'])
        #
        # memory = oocd.read_memory(0x20000000, 10, 32, phys=True)
        # print([hex(x) for x in memory])
        time.sleep(5)
        oocd.write_memory(0x0000000020000484, [i], 32)

    print(f'for {max_i} read write {time.time() - start}')
    # oocd.resume()
