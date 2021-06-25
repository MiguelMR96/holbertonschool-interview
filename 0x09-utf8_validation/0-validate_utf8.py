def validUTF8(data):
    """
    :type data: List[int]
    :rtype: bool
    """

    # Number of bytes in the current UTF-8 character
    n_bytes = 0

    # For each integer in the data array.
    for num in data:

        # for any given number.
        bin_rep = format(num, '#010b')[-8:]
        if n_bytes == 0:

            # Get the number of 1s in the beginning of the string.
            for bit in bin_rep:
                if bit == '0':
                    break
                n_bytes += 1

            # 1 byte characters
            if n_bytes == 0:
                continue

            # Invalid scenarios according to the rules of the problem.
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            # Else, we are
            if not (bin_rep[0] == '1' and bin_rep[1] == '0'):
                return False

        # We reduce the number of bytes to process by 1 after each integer.
        n_bytes -= 1

    # This is for the case where we might not have the complete data for
    # a particular UTF-8 character.
    return n_bytes == 0
