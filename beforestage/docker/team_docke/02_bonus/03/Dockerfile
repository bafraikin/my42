FROM python

RUN python3 -m venv venv && . ./venv/bin/activate

RUN pip install requests BeautifulSoup4

RUN echo "from requests import get" > mathematicians.py \
&& echo "from requests.exceptions import RequestException" >> mathematicians.py \
&& echo "from contextlib import closing" >> mathematicians.py \
&& echo "from bs4 import BeautifulSoup" >> mathematicians.py
