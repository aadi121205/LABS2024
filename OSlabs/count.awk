{
    chars += length($0) + 1  # Adding 1 for the newline character
    words += NF
    lines += 1
}

END {
    print "Number of characters:", chars
    print "Number of words:", words
    print "Number of lines:", lines
}
