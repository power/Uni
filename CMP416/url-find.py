import re

def extract_unique_urls(input_file, output_file):
    # Define a regex pattern for URLs
    url_pattern = re.compile(r'https?://[^\s]+')

    # Use a set to store unique URLs
    unique_urls = set()

    # Read the input file and find URLs
    with open(input_file, 'r') as file:
        for line in file:
            urls = url_pattern.findall(line)
            unique_urls.update(urls)

    # Write the unique URLs to the output file
    with open(output_file, 'w') as file:
        for url in sorted(unique_urls):
            file.write(url + '\n')

if __name__ == "__main__":
    input_file = 'alert.txt'  # Change this to your input file
    output_file = 'unique_urls.txt'  # Change this to your desired output file
    extract_unique_urls(input_file, output_file)
    print(f'Unique URLs have been written to {output_file}')
