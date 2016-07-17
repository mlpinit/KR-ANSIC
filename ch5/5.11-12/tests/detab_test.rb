require "minitest/autorun"

class DetabTest < Minitest::Test

  def test_starting_position_and_nth_column
    input_file = "detab_test/four_tabs.txt"
    output_file = "detab_test/four_tabs.result"
    system(".././detab -3 +4 < #{input_file} > #{output_file}")

    output_text = IO.read(output_file)
    expected_output_text = IO.read("detab_test/four_tabs.expected_result")
    assert_equal expected_output_text, output_text
  end

  def test_provided_ints_for_tab_stops
    input_file = "detab_test/provided_ints.txt"
    output_file = "detab_test/provided_ints.result"
    system(".././detab 3 8 13 < #{input_file} > #{output_file}")

    output_text = IO.read(output_file)
    expected_output_text = IO.read("detab_test/provided_ints.expected_result")
    assert_equal expected_output_text, output_text
  end

  def test_default
    input_file = "detab_test/default_tab.txt"
    output_file = "detab_test/default_tab.result"
    system(".././detab < #{input_file} > #{output_file}")

    output_text = IO.read(output_file)
    expected_output_text = IO.read("detab_test/default_tab.expected_result")
    assert_equal expected_output_text, output_text 
  end

end
